#include "include/coolBananaLogger.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *PrintMessage(void *psMsg){
    int *pIntMsg = (int *)psMsg;
    printf("number of thread %d\n", *pIntMsg);
    return NULL;
}

int main(void){

    pthread_t pThread1, pThread2;
    int one = 1;
    int two = 2;

    printf("Before starting threads\n");

    pthread_create(&pThread1, NULL, PrintMessage,(void*) &one);
    pthread_create(&pThread2, NULL, PrintMessage, (void*) &two);

    printf("Threads have started\n");

    pthread_join(pThread1, NULL);

    pthread_join(pThread2, NULL);

    printf("Threads have finished\n");
}