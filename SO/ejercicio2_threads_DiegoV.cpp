/*
*------------------------------------------
* ejercicio2_threads_DiegoV.cpp
* -----------------------------------------
* UNIVERSIDAD DEL ISTMO
* FACULTAD DE INGENIERÍA
*------------------------------------------
* Descripción: Ejercicio velocidad, tiempo, distancia con hilos
* Estudiante: Diego Vallejo
*------------------------------------------
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream> 
#include <vector>
#include <numeric>
#include <functional>
#include <chrono>
#include <unistd.h>

using namespace std;

#define VUELTAS 50

struct informacion {
    int tiempo;
    int velocidad;
    int recorrido;
};

void *hilo1(void *element) { //subrutina hilo1
    informacion *info;
    info = (informacion *) element;
	int actual;
	actual = info->tiempo;
	cout << "El valor del hilo 1 es: " << actual << " segundo(s)." << endl;
	pthread_exit(NULL);
	return 0;
}

void *hilo2(void *element){ //subrutina hilo2 
    informacion *info; 
    info = (informacion *) element;
    int actual, velocidad;
    actual = info->tiempo;
    velocidad = info->velocidad;
    cout << "En " << actual << " segundos, la distancia recorrida es: " << actual * velocidad << " metros." << endl;
    pthread_exit(NULL);
    return 0;
    
}

void *hilo3(void *element) { //subrutina hilo 3
    informacion *info;
    info = (informacion *) element;
    int recorrido;
    recorrido = info->recorrido;
    //se imprimen las ====><==== para que se note mejor al imprimirlo. 
    cout << "====>Se han recorrido: " << recorrido << " metros.<====" << endl;
    pthread_exit(NULL);
    return 0;
}

int main() {
    informacion info; 
    
    int rc1, rc2, rc3, i1, i2, recorrido;

    cout << "Velocidad en m/s: " << endl;
    cin >> info.velocidad;
    
    int thread1, thread2, thread3; 
    //hilo1 
    pthread_t t1id;
    pthread_attr_t attr1;
    pthread_attr_init(&attr1);
    pthread_attr_setdetachstate(&attr1, PTHREAD_CREATE_JOINABLE);
    //hilo2
    pthread_t t2id;
    pthread_attr_t attr2;
    pthread_attr_init(&attr2);
    pthread_attr_setdetachstate(&attr2, PTHREAD_CREATE_JOINABLE);
    //hilo3
    pthread_t t3id;
    pthread_attr_t attr3;
    pthread_attr_init(&attr3);
    pthread_attr_setdetachstate(&attr3, PTHREAD_CREATE_JOINABLE);
    
    //funcion para definir los ciclos.
	for (i1 = 1; i1 <= VUELTAS; i1++){
		sleep(1);
		info.tiempo = i1; 
		rc1 = pthread_create(&t1id, &attr1, hilo1, (void *)&info);
		rc2 = pthread_create(&t2id, &attr2, hilo2, (void *)&info);
		
		if (i1 % 10 == 0) {
		    info.recorrido = info.tiempo * info.velocidad;
		    rc3 = pthread_create(&t3id, &attr3, hilo3, (void *)&info);
		}
	}
	
	//para finalizar:
	
	rc1 = pthread_join(t1id, NULL);
	rc2 = pthread_join(t2id, NULL);
	rc3 = pthread_join(t3id, NULL);
	
	pthread_attr_destroy(&attr1);
	pthread_attr_destroy(&attr2);
	pthread_attr_destroy(&attr3);
	pthread_exit(NULL);

}