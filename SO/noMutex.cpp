/*
 * UNIVERSIDAD DEL ISTMO
 * Sistemas Operativos
 * Date:	2022/08/25
 * Ver:		2.0 - 2022/08/19
 * 
 * noMutex.cpp
 * Demuestra comportamiento de acceso de pthreads 
 * asegmento crítico: incremento de variable mails,
 * en operación no atómica.
 */
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;

void* routine(void *arg) {
    for (int i = 0; i < 1000000; i++) {
        mails++;
        // read mails
        // increment
        // write mails
    }
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    pthread_t p1, p2, p3, p4;
    if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
        return 2;
    }
    if (pthread_create(&p3, NULL, &routine, NULL) != 0) {
        return 3;
    }
    if (pthread_create(&p4, NULL, &routine, NULL) != 0) {
        return 4;
    }
    if (pthread_join(p1, NULL) != 0) {
        return 5;
    }
    if (pthread_join(p2, NULL) != 0) {
        return 6;
    }
    if (pthread_join(p3, NULL) != 0) {
        return 7;
    }
    if (pthread_join(p4, NULL) != 0) {
        return 8;
    }
    printf("Number of mails: %d\n", mails);
    return 0;
}