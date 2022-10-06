#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>

// Contiene todas los arreglos de permutaciones, matrices de mapeado, entre otros
#include "matrices.h"
// Contiene funciones de utilidad que no son específicas al algoritmo de encripción/desencripción
#include "utils.h"

using namespace std;

// La cantidad de rondas de encripción o desencripción que se van a hacer
#define ROUNDS 4

// Los procesos de generación de subllaves y de permutación de bloques de mensaje se pueden hacer
// de manera independiente, pero se tiene que esperar a que terminen ambos para comenzar a
// encriptar o desencriptar. Esta barrera controla esto
pthread_barrier_t barreraEncripcion;

// Aquí se van a insertar las subllaves en lo que se van generando
// Mutex para proteger la escritura a esta variable ya que se modifica desde varios hilos
pthread_mutex_t lockSubkeys;
vector<string> subkeys(ROUNDS);

// Aquí se van a insertar los resultados de encripción o desencripción
// Mutex para proteger la escritura a esta variable ya que se modifica desde varios hilos
pthread_mutex_t lockResults;
vector<string> results;

// Los algoritmos de encripción y desencripción no son muy diferentes entre sí, por lo que
// solo lo controlamos con una variable booleana
bool decrypting = false;

// struct para los hilos que generan las subllaves que guardan qué subllave tienen que generar
// y la llave a partir de la cual la generan
typedef struct {
    size_t id;
    string key;
} permutacionActual;

// struct para los hilos que permutan y encriptan los bloques que guardan qué bloque están
// encriptando y su contenido
typedef struct {
    size_t id;
    string bin;
} mensajeActual;

// Subrutina de permutación y encripción de bloques de bloques
// arg corresponde a un struct mensajeActual
void *encriptarMensaje(void *arg) {
    mensajeActual mens = *(mensajeActual *)arg;
    string bin = mens.bin;

    // Se aplica la permutación IP
    string ipbin;
    for (int i = 0; i < 64; i++) {
        ipbin.push_back(bin[ip[i]]);
    }

    // Se divide el bloque en dos mitades L y R de 32 bits
    string leftPrev = ipbin.substr(0, 32);
    string rightPrev = ipbin.substr(32, 32);

    // Se espera a que termine la permutación de los demás bloques y la generación de las subllaves
    pthread_barrier_wait(&barreraEncripcion);

    for (size_t i = 0; i < subkeys.size(); i++) {
        // Se obtiene la subllave K que corresponde a esta ronda
        // En desencripción, se aplican las llaves de manera inversa
        string key;
        if (decrypting) {
            key = subkeys[subkeys.size() - i - 1];
        } else {
            key = subkeys[i];
        }

        // Se aplica la permutación E-Bit Selection a R, dándonos un bloque de 48 bits
        string er;
        for (int i = 0; i < 48; i++) {
            er.push_back(rightPrev[ebs[i]]);
        }

        // cout << i << "E(R) = " << er << endl;

        // Se aplica un XOR entre la subllave K y el resultado anterior, dándonos un bloque de 48 bits
        string kxer;
        for (int i = 0; i < 48; i++) {
            char bit = key[i] == er[i] ? '0' : '1';
            kxer.push_back(bit);
        }

        // cout << i << "K + E(R) = " << kxer << endl;

        // Se aplican las matrices 2D de mapeado (llamadas S) al resultado anterior
        // En este caso se subdivide K xor E(R) en grupos de 6 bits
        // - Se toma el primer bit y el último bit y se juntan, esto es la coordenada en y
        // - Se toman los cuatro bits de en medio, esto es la coordenada en x
        // - Según el bloque que se está tratando se obtiene el valor de la matriz S1, S2, ..., S7, S8
        //   con las coordenadas obtenidas. Obtenemos un número de 4 bits.
        // Finalmente se vuelven a unir todos los bloques, dándonos un bloque de 32 bits
        string skxer;
        for (size_t j = 0; j < kxer.size(); j += 6) {
            string group = kxer.substr(j, 6);

            // Primer y último bit
            string ystr = group.substr(0, 1) + group.substr(5, 1);
            // Cuatro bits de en medio
            string xstr = group.substr(1, 4);

            size_t y = BinaryToNum(ystr);
            size_t x = BinaryToNum(xstr);

            // Para el primer bloque, la tabla S1; para el segundo bloque la matriz S2; etc.
            int val = sTables[j/6][y][x];

            skxer.append(NumToBinary(val, 4));
        }

        // cout << i << "S(K + E(R)) = " << skxer << endl;

        // Se aplica la permutación P al resultado anterior, dándonos un bloque de 32 bits
        string pskxer;
        for (int i = 0; i < 32; i++) {
            pskxer.push_back(skxer[p[i]]);
        }

        // cout << i << "P(S(K + E(R))) = " << pskxer << endl;

        // Se aplica un XOR entre L y el resultado anterior, dándonos un bloque de 32 bits
        string lpskxer;
        for (int i = 0; i < 32; i++) {
            char bit = leftPrev[i] == pskxer[i] ? '0' : '1';
            lpskxer.push_back(bit);
        }

        // cout << i << "L + P(S(K + E(R))) = " << lpskxer << endl;

        // Se asignan
        // Siguiente L = R
        // Siguiente R = L xor P(S(K xor E(R)))
        string left = rightPrev;
        string right = lpskxer;

        // y se continua a la siguiente ronda
        leftPrev = left;
        rightPrev = right;
    }

    // Se une el resultado en orden inverso, dándonos un bloque de 64 bits
    string rl = rightPrev + leftPrev;

    // cout << "RL = " << rl << endl;

    // Se aplica la permutación IP^-1 a RL
    string result;
    for (int i = 0; i < 64; i++) {
        result.push_back(rl[ip_1[i]]);
    }

    // cout << "FINAL = " << result << endl;

    // Finalmente se sincronizan los resultados en el orden correcto
    pthread_mutex_lock(&lockResults);
    // Nos aseguramos que el vector tenga espacio suficiente para agregar el mensaje
    // ya que se inicializa con longitud 0
    if (mens.id >= results.size()) {
        results.resize(mens.id + 1);
    }
    // Se inserta el resultado en la posición correcta
    results[mens.id] = result;
    pthread_mutex_unlock(&lockResults);

    pthread_exit(NULL);
    return NULL;
}

// Subrutina de permutación y generación de subllaves
// arg corresponde a un struct permutacionActual
void *generarSubllaves(void *arg) {
    permutacionActual perm = *(permutacionActual *)arg;

    // Se divide la llave de 56 bits en dos mitades de 28 bits
    string chalf = perm.key.substr(0, 28);
    string dhalf = perm.key.substr(28, 28);

    // A cada llave se le debe aplicar un shift diferente según a la ronda que corresponda
    int shift = shifting[perm.id];

    // Se aplica este shift a cada mitad de la llave
    string cshift = chalf.substr(shift, 28 - shift) + chalf.substr(0, shift);
    string dshift = dhalf.substr(shift, 28 - shift) + dhalf.substr(0, shift);

    // y se concatenan
    string concat = cshift + dshift;

    // Se aplica la permutación PC-2 a esta concatenación, dándonos una subllave de 48 bits
    string subkey;
    for (int j = 0; j < 48; j++) {
        subkey.push_back(concat[pc2[j]]);
    }

    // Finalmente se sincronizan las subllaves en el orden correcto
    pthread_mutex_lock(&lockSubkeys);
    // El tamaño de subkeys está predefinido así que no tenemos que hacer nada para asegurar que
    // haya espacio en el vector
    subkeys[perm.id] = subkey;
    pthread_mutex_unlock(&lockSubkeys);

    // Finalmente se espera a que termine la generación de las demás subllaves y la permutación
    // de los bloques
    pthread_barrier_wait(&barreraEncripcion);

    // No hay nada más que hacer en esta subrutina

    pthread_exit(NULL);
    return NULL;
}

int main() {
    string decision;
    cout << "Encripción o desencripción? (E/D): ";
    getline(cin, decision);
    cout << endl;
    // Si el usuario da cualquier otra respuesta, se asume que quiere encriptar
    if (decision == "D") {
        decrypting = true;
    } else {
        decrypting = false;
    }

    string hexNumber;
    cout << "Ingrese la llave que se usará para el cifrado (Hexadecimal) (16 dígitos): "; 
    getline(cin, hexNumber);
    cout << endl;
    string key = hexToBinary(hexNumber);

    string mensaje;
    if (decrypting) { // Personalización de mensaje
        cout << "Ingrese el mensaje a desencriptar (Hexadecimal): ";
    } else {
        cout << "Ingrese el mensaje a encriptar (ASCII): ";
    }
    getline(cin, mensaje);
    cout << endl;
    // Los textos cifrados están en hexadecimal ya que no hay garantía de que sean ASCII legible
    string mensajeBin;
    if (decrypting) {
        mensajeBin = hexToBinary(mensaje);
    } else {
        mensajeBin = ASCIIToBinary(mensaje);
    }

    // Se divide el mensaje en bloques de 64 bits
    vector<string> bin64;

    bool empty = false;
    while (empty == false) {
        if (mensajeBin == "") {
            empty = true;
        } else {
            // Se inserta los primeros 64 bits del mensaje a bin64
            bin64.push_back(mensajeBin.substr(0, 64));
            // y se eliminan del mensaje
            mensajeBin.erase(0, 64);
        }
    }

    // Revisar si hay algún bloque con menos de 64 bits y completarlo con 0s
    for (size_t i = 0; i < bin64.size(); i++) {
        if (bin64[i].size() < 64) {
            for (size_t j = bin64[i].size(); j < 64; j++) {
                bin64[i].push_back('0');
            }
        }
    }

    // Se aplica la permutación PC-1 a la llave, dándonos una llave de 56 bits
    string key56;
    for (int i = 0; i < 56; i++) {
        key56.push_back(key[pc1[i]]);
    }

    size_t numHilosMensaje = bin64.size();

    // La barrera aplica a cada hilo de los bloques y cada hilo de las subllaves
    // Sabemos que hay una cantidad total de hilos de numHilosMensaje + ROUNDS
    pthread_barrier_init(&barreraEncripcion, NULL, numHilosMensaje + ROUNDS);
    pthread_mutex_init(&lockSubkeys, NULL);
    pthread_mutex_init(&lockResults, NULL);

    pthread_t hilosMensaje[numHilosMensaje];
    mensajeActual hilosMens[numHilosMensaje];

    for (size_t i = 0; i < numHilosMensaje; i++) {
        // el struct mensajeActual guarda el índice del bloque a trabajar y el contenido del bloque
        hilosMens[i] = {
            i,
            bin64[i],
        };
        pthread_create(&hilosMensaje[i], NULL, encriptarMensaje, (void *)&hilosMens[i]);
    }

    pthread_t hilosHalf[ROUNDS];
    permutacionActual hilosPermHalf[ROUNDS];

    for (size_t i = 0; i < ROUNDS; i++) {
        // el struct permutacionActual guarda el índice de la subllave a trabajar y la llave original
        hilosPermHalf[i] = {
            i,
            key56,
        };
        pthread_create(&hilosHalf[i], NULL, generarSubllaves, (void *)&hilosPermHalf[i]);
    }

    // Se unifican todos los hilos
    for (size_t i = 0; i < numHilosMensaje; i++) {
        pthread_join(hilosMensaje[i], NULL);
    }

    for (size_t i = 0; i < ROUNDS; i++) {
        pthread_join(hilosHalf[i], NULL);
    }

    // Una vez unificados, se concatenan los resultados de la encripción a desencripción
    string result;
    for (size_t i = 0; i < results.size(); i++) {
        result.append(results[i]);
    }

    // Se convierten a ASCII o hexadecimal según la operación que se pidió
    if (decrypting) {
        result = binaryToAscii(result);
    } else {
        result = binaryToHex(result);
    }

    // y se muestra el resultado al usuario
    cout << "Resultado: " << result << endl;

    pthread_exit(NULL);
    return 0;
}