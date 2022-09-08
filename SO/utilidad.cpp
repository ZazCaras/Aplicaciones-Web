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

using namespace std;

#define JULIO 8;
long long ventas_julio = 0.0;
long long utilidad_julio = 0.0;
#define AGOSTO 8;
long long ventas_agosto = 0.0;
long long utilidad_agosto = 0.0;
//el join de los hilos por separadoooooo
pthread_mutex_t vestidor; 

void *julio(void *item) {
    return NULL;
};

void *agosto(void *item) {
    return NULL;
};

int main() {

};

