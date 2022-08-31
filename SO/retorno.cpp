/*---------------------------------------
UNIVERSIDAD DEL VALLE DE GUATEMALA
CC3086 - Programacion de Microprocesadores
Modificado por: Kimberly Barrera
Fecha: 08/11/2020
Mod:   08/19/2022

Nueva Modificacion: Diego Vallejo 08/30/2022

retorno.cpp
Comparte desde subrutina argumento puntero
de tipo void, por medio de return.
---------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream> 

using namespace std;


void *calculos(void* argument){
	
	float input;
	input = *(float *) &argument; 
	//puntero a void -> puntero a puntero a void -> cast de puntero a float de puntero a puntero a void -> desreferencia de puntero a float


	float output;
	output = input*2;
	return *(void**) &output;
	//float -> puntero a float -> doble a puntero a void -> desreferencia de doble puntero a void para tener un unico puntero a void
}
int main(){

	printf("\n\n");
	pthread_t thread_id;
	pthread_attr_t attr;
	
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	
	void *exit_value;
	float result = 1;
	
	for(float i = 0.7; i < 100; i++){
		pthread_create(&thread_id, &attr, calculos, *(void**)&i);
		pthread_join(thread_id, &exit_value);
		
		float result = *(float *) &exit_value;
		cout << "Resultado multiplicaciÃ³n es: \n " << result << endl;
	}
	
	pthread_attr_destroy(&attr);
	pthread_exit(NULL);
	return 0;
	
}