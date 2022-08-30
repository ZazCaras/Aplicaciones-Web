/*---------------------------------------
UNIVERSIDAD DEL VALLE DE GUATEMALA
CC3086 - Programacion de Microprocesadores
Modificado por: Kimberly Barrera
Fecha: 08/11/2020
Mod:   08/19/2022

retorno.cpp
Comparte desde subrutina argumento puntero
de tipo void, por medio de return.
---------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *calculos(void* argument){
	
	long long input;
	input = (long long) argument;
	
	long long output;
	output = input*2;
	return (void*) output;
}
int main(){

	printf("\n\n");
	pthread_t thread_id;
	pthread_attr_t attr;
	
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	
	void *exit_value;
	unsigned int result = 1;
	
	for(long long i = 0; i < 100; i++){
		pthread_create(&thread_id, &attr, calculos, (void*)i);
		pthread_join(thread_id, &exit_value);
		
		long long result = (long long) exit_value;
		printf("Resultado multiplicaciÃ³n es: %lld\n ", result);
	}
	
	pthread_attr_destroy(&attr);
	pthread_exit(NULL);
	return 0;
	
}