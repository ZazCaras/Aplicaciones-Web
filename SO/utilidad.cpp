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

#define JULIO 8;
long long ventas_julio = 0.0;
long long utilidad_julio = 0.0;
vector<int> uVentas_julio{300, 400, 1590, 200, 390, 1455, 800, 60};
#define AGOSTO 8;
long long ventas_agosto = 0.0;
long long utilidad_agosto = 0.0;
vector<int> uAgosto{250, 380, 800, 250, 600, 1200, 1540, 15};

//el join de los hilos por separadoooooo
pthread_mutex_t vestidor; 

vector<double> precio{60.00, 32.00, 22.00, 24.00, 28.00, 24.00, 32.00, 60.00};
vector<double> costo{20.00, 19.20, 13.20, 17.20, 20.10, 17.20, 23.00, 20.00};



void *julio(void *item) {
    return NULL;
};

void *agosto(void *item) {
    return NULL;
};

int main() {

};

