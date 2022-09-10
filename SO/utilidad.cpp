/*
 * UNIVERSIDAD DEL ISTMO
 * Sistemas Operativos
 *
 * utilidad.cpp
 * Diego V
 */

#include <iostream>
#include <stdio.h>		
#include <cmath>		
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <numeric>

using namespace std;

const int JULIO = 8;
long long ventas_total_julio = 0.0;
long long utilidad_total_julio = 0.0;
vector<int> unidad_julio{300, 400, 1590, 200, 390, 1455, 800, 60};
vector<double>ventas_julio(8);
vector<double>utilidad_julio(8);

const int AGOSTO = 8;
long long ventas_total_agosto = 0.0;
long long utilidad_total_agosto = 0.0;
vector<int> unidad_agosto{250, 380, 800, 250, 600, 1200, 1540, 15};
vector<double>ventas_agosto(8);
vector<double>utilidad_agosto(8);

//el join de los hilos por separadoooooo
pthread_mutex_t vestidorJulio, vestidorAgosto; 

vector<double> precio{60.00, 32.00, 22.00, 24.00, 28.00, 24.00, 32.00, 60.00};
vector<double> costo{20.00, 19.20, 13.20, 17.20, 20.10, 17.20, 23.00, 20.00};
vector<string> nombres{"Porcion Pastelito Chocolate", "White Mocha", "Cafe americano 8onz", "Latte 8onz", "Toffee Coffee", "Capucchino 8onz", "Smores Latte", "Cafe Tostado Molido"};

void *julio(void *item) {
    long valor = (long)item;
    long long ventasProducto, utilidadProducto, totalVentas, totalUtilidad;
    cout << "calculo hilo JULIO " << valor << " iniciado." << endl;
    sleep(1);
    pthread_mutex_lock(&vestidorJulio);
    ventasProducto = unidad_julio[valor] * precio[valor];
    utilidadProducto = ventasProducto - (costo[valor] * unidad_julio[valor]);
    ventas_julio[valor] = ventasProducto;
    utilidad_julio[valor] = utilidadProducto;
    pthread_mutex_unlock(&vestidorJulio);
    cout << "calculo hilo JULIO " << valor << " terminado." << endl;

    return NULL;
};

void *agosto(void *item) {
    long valor = (long)item;
    long long ventasProducto, utilidadProducto, totalVentas, totalUtilidad;
    cout << "calculo hilo AGOSTO " << valor << " iniciado." << endl;
    sleep(1);
    pthread_mutex_lock(&vestidorAgosto);
    ventasProducto = unidad_agosto[valor] * precio[valor];
    utilidadProducto = ventasProducto - (costo[valor] * unidad_agosto[valor]);
    ventas_agosto[valor] = ventasProducto;
    utilidad_agosto[valor] = utilidadProducto;
    pthread_mutex_unlock(&vestidorAgosto);
    cout << "calculo hilo AGOSTO " << valor << " terminado." << endl;


    return NULL;
};

int main() {
    long long j, a, rcJ, rcA;
    pthread_t threadsJulio[JULIO], threadsAgosto[AGOSTO];
    pthread_mutex_init(&vestidorJulio, NULL);
    pthread_mutex_init(&vestidorAgosto, NULL);

    for(long long i = 0; i < JULIO; i++) {
        rcJ = pthread_create(&threadsJulio[i], NULL, julio, (void *)i);
    }

    for(long long i = 0; i < AGOSTO; i++) {
        rcA = pthread_create(&threadsAgosto[i], NULL, agosto, (void *)i);
    }
    
    for(long long i = 0; i < JULIO; i++) {
        rcJ = pthread_join(threadsJulio[i], NULL);
    }
    for(long long i = 0; i < AGOSTO; i++) {
        rcA = pthread_join(threadsAgosto[i], NULL);
    }

    pthread_mutex_destroy(&vestidorJulio);

    pthread_mutex_destroy(&vestidorAgosto);

    cout << "--- REPORTE DEL MES DE JULIO ---\n" << endl;
    cout << "- Ventas por producto -" << endl;
    for(int i = 0; i < JULIO; i++) {
        cout << nombres[i] << ": Q." << ventas_julio[i] << endl;
    }
    cout << "\n- Utilidad por producto -" << endl;
    for (int i = 0; i < JULIO; i++) {
        cout << nombres[i] << ": Q." << utilidad_julio[i] << endl;
    }
    int costos_julio = 45640;
    cout << "\nTotal ventas: Q." << accumulate(ventas_julio.begin(), ventas_julio.end(), 0) << endl;
    cout << "Costos variables: Q." << costos_julio << endl;
    cout << "Utilidad del mes: Q." << (accumulate(utilidad_julio.begin(), utilidad_julio.end(), 0) - costos_julio) << "\n" << endl;

    cout << "--- REPORTE DEL MES DE AGOSTO ---\n" << endl; 
    cout << "- Ventas por producto -" << endl;
    for (int i = 0; i < AGOSTO; i++) {
        cout << nombres[i] << ": Q." << ventas_agosto[i] << endl;
    }
    cout << "\n- Utilidad por producto -" << endl;
    for (int i = 0; i < AGOSTO; i++) {
        cout << nombres[i] << ": Q." << utilidad_agosto[i] << endl;
    }
    int costos_agosto = 40590;
    cout << "\nTotal ventas: Q." << accumulate(ventas_agosto.begin(), ventas_agosto.end(), 0) << endl;
    cout << "Costos variables: Q." << costos_agosto << endl;
    cout << "Utilidad del mes: Q." << (accumulate(utilidad_agosto.begin(), utilidad_agosto.end(), 0) - costos_agosto) << "\n" << endl;

};
