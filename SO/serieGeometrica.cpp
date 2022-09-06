/*
 * UNIVERSIDAD DEL ISTMO
 * Sistemas Operativos
 *
 * Serie.cpp
 * Diego V
 */
 
#include <iostream>
#include <stdio.h>		//printf
#include <cmath>		//pow
#include <pthread.h>	

using namespace std;

const long long N = pow(10,10);
//---- Cuidar que THREAD_COUNT sea factor de N
const int THREAD_COUNT = 10;

//---- suma y bandera globales
long double sum = 0.0;
int flag = 0;

pthread_mutex_t vestidor; 
//------------
// Calculo de serie ejercicio
//------------
void *threadSum(void *thread_rank)
{
	long my_rank = (long)thread_rank;
    double factor, my_sum = 0.0;  //*** Suma local
	long long i;
	//---- Lote de datos de cada thread
	long long my_n = N/THREAD_COUNT;
	//---- Rango de datos para cada hilo
	long long my_first_i = (my_n * my_rank) + 1;
	long long my_last_i = my_first_i + my_n;
	
	//---- Magnitud de cada elemento de la serie
	for(i=my_first_i; i<my_last_i; i++)
	{
		my_sum += 1/(double)(i*(i+1));

	}
	pthread_mutex_lock(&vestidor);

	//---- Busy-waiting para actualizar variable y bandera global
	sum += my_sum;  //Copia del resultado parcial del hilo a mem-global
	//flag = (flag + 1) % THREAD_COUNT;
	pthread_mutex_unlock(&vestidor);
	pthread_exit(NULL);
	
	return NULL;
}

int main()
{
	long long i, rc;
	pthread_t threads[THREAD_COUNT];
	pthread_mutex_init(&vestidor, NULL);
	for(i=0;i<THREAD_COUNT;i++)
	{
		rc = pthread_create(&threads[i],NULL,threadSum,(void *)i);
		if(rc)
		{
			cout<<">>>Error creating threads"<<endl;
			exit(-1);
		}
	}
	for(i=0;i<THREAD_COUNT;i++) {
		rc = pthread_join(threads[i],NULL);
		if(rc)
		{
			cout<<"No se pudo unir el hilo "<<i<<endl;
			exit(-1);
		}
	}
	pthread_mutex_destroy(&vestidor);
	printf("VALOR= %.10Lf\n",sum);
	return 0;
}
