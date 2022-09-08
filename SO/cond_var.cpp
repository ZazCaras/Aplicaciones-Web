/*---------------------------------------
* UNIVERSIDAD DEL ISTMO
* Sistemas Operativos
* Autor: AndrÃ©s MondragÃ³n Contreras
* Mod.: KB
* Ver.: 1.01
* Fecha: 2022/08/29
*
* References:
* ------
* "SincronizaciÃ³n: Mutex, Variables condiciÃ³n y SemÃ¡foros."  
* Universidad Nacional Autonoma de Mexico
* Facultad de Ingenieria
* "Laboratorio Intel para la academia"
* ---------------------------------------
* Variables de condiciÃ³n p/acceder a 
* region crÃ­tica 
* variables de condiciÃ³n.
*----------------------------------------
*/

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t candado;
pthread_cond_t cond1, cond2;

void *menos(void *arg)
{
	int i;
	int *x = (int *)arg;
	for (i = 0; i < 9; i++) {
		pthread_mutex_lock(&candado);				//  -1 -2 -3 -4 -5 -6 -7 -8 -9 -8 -7 -6 -5 ... 0
		//        printf("%3d", *x);                //  1 2 3 4 5 6 7 8 9 8 7 6 5 4 ...0
		*x = *x - 1;
		pthread_mutex_unlock(&candado);
        if (i < 4) {
            pthread_cond_signal(&cond1);
        }
        else if (i > 4 && i < 10) {
            pthread_cond_signal(&cond2);
        }

	}
    //        pthread_cond_signal(&cond);

	return NULL;
}


void *por5(void *arg)
{
	int i;
	int *x = (int *)arg;
	pthread_mutex_lock(&candado);
	if (*x == 0)
		pthread_cond_wait(&cond1, &candado);			//AQUÃ// bloquea al hilo que la llama hasta que la seÃ±al signal se habilita sobre cond
	for (i = 0; i < 5; i++) {
	    *x = *x * 5;
	    printf("%5d", *x);
	}
	
	pthread_mutex_unlock(&candado);
	return NULL;
}

void *por2(void *arg){
    int i; 
    int *x = (int *)arg;
    pthread_mutex_lock(&candado);
    if (*x == 0)
        pthread_cond_wait(&cond2, &candado);
    for (i = 0; i < 4; i++) {
        *x = *x *2;
        printf("%5d", *x);
    }
    pthread_mutex_unlock(&candado);
    return NULL;
}



int main()
{
	pthread_t hilo_por5, hilo_menos, hilo_por2;
	int x = 0;
	
	pthread_mutex_init(&candado, NULL);
	pthread_cond_init(&cond1, NULL);
    pthread_cond_init(&cond2, NULL);
	
    pthread_create(&hilo_menos, NULL, menos, (void *)&x);
	pthread_create(&hilo_por5, NULL, por5, (void *)&x);
    pthread_create(&hilo_por2, NULL, por2, (void *)&x);

	pthread_join(hilo_menos, NULL);
    pthread_join(hilo_por5, NULL);
    pthread_join(hilo_por2, NULL);
	printf("\n");
	
	
	pthread_cond_destroy (&cond1);
    pthread_cond_destroy (&cond2);

}
