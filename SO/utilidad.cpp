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

using namespace std;

const int JULIO = 8;
long long ventas_julio = 0.0;
long long utilidad_julio = 0.0;
vector<int> unidad_julio{300, 400, 1590, 200, 390, 1455, 800, 60};

const int AGOSTO = 8;
long long ventas_agosto = 0.0;
long long utilidad_agosto = 0.0;
vector<int> unidad_agosto{250, 380, 800, 250, 600, 1200, 1540, 15};

//el join de los hilos por separadoooooo
pthread_mutex_t vestidorJulio, vestidorAgosto; 

vector<double> precio{60.00, 32.00, 22.00, 24.00, 28.00, 24.00, 32.00, 60.00};
vector<double> costo{20.00, 19.20, 13.20, 17.20, 20.10, 17.20, 23.00, 20.00};
vector<string> nombres{"Porcion Pastelito Chocolate", "White Mocha", "Cafe americano 8onz", "Latte 8onz", "Toffee Coffee", "Capucchino 8onz", "Smores Latte", "Cafe Tostado Molido"};

void *julio(void *item) {
    long valor = (long)item;
    long long ventasProducto, utilidadProducto, totalVentas, totalUtilidad;

    ventasProducto = unidad_julio[valor] * precio[valor];
    utilidadProducto = ventasProducto - costo[valor];
    cout << ventasProducto << utilidadProducto << endl; 

    return NULL;
};

void *agosto(void *item) {
    long valor = (long)item;
    long long ventasProducto, utilidadProducto, totalVentas, totalUtilidad;

    ventasProducto = unidad_agosto[valor] * precio[valor];
    utilidadProducto = ventasProducto - costo[valor];
    cout << ventasProducto << utilidadProducto << endl; 
    return NULL;
};

int main() {
    long long j, a, rcJ, rcA;
    pthread_t threadsJulio[JULIO], threadsAgosto[AGOSTO];
    pthread_mutex_init(&vestidorJulio, NULL);
    pthread_mutex_init(&vestidorAgosto, NULL);

    for(j = 0; j < JULIO; j++) {
        rcJ = pthread_create(&threadsJulio[j], NULL, julio, (void *)j);

    }
    for(a = 0; a < AGOSTO; a++) {
        rcA = pthread_create(&threadsAgosto[a], NULL, julio, (void *)a);
    }
};

