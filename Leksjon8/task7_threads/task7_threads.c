#include "include/coolBananaLogger.h"
#include "include/threadBuf.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#define MAX_INPUT_LENGTH 4095
int main(int argC, char *argv[]){


    char szInput[MAX_INPUT_LENGTH + 1] = ""; // +1 for zero terminator

    SHAREDBUFFER *psBuf = malloc(sizeof (SHAREDBUFFER));
    // Exit program if malloc fails
    if (psBuf == NULL){
        bananaDebug("Failed to alloc memory for SHAREDBUFFER!\n");
        bananaError("Failed to alloc memory for SHAREDBUFFER!\n");
        return 0;
    }
    psBuf ->iExitFlag = 0;

    // sem_init does not work on macOS, have to compile on linux
    // would use sem_open on macOS
    if (sem_init(&psBuf->semDataReady, 0, 0) == -1){ // handle error on fail
        bananaError("Failed to init semaphore\n");
        return 0;
    }
    if (sem_init(&psBuf->semDataProcessed, 0, 0) == -1){ // handle error on fail
        bananaError("Failed to init semaphore\n");
        return 0;
    }


    // init thread
    pthread_t threadId;
    // Start thread with function
    if (pthread_create(&threadId, NULL, workerThread, (void*) psBuf) != 0){ // handle error on fail
        bananaError("Failed to start thread!\n");
        return 0;
    }


    while (psBuf->iExitFlag == 0){
        printf("Enter a text string and press enter. Write 'quit' to exit program.\n");
        printf("Enter input (up to %d characters): \n", MAX_INPUT_LENGTH);

        char *psTmp = fgets(szInput, MAX_INPUT_LENGTH, stdin);
        if (psTmp != NULL){
            printf("yohoho %c\n", *psTmp);
        }

        if (strcmp(szInput, "quit\n") != 0){

            int iCount = 0;
            while (iCount <= (strlen(szInput) - 1)){

                strncpy(psBuf->cBuf, &szInput[iCount], 10);
                psBuf->cBuf[10] = '\0';

                // let thread know we are ready to start
                if (sem_post(&psBuf->semDataReady) != 0){
                    bananaError("Failed on sem_post\n");
                    return 0;
                }

                // wait for thread to finish
                if (sem_wait(&psBuf->semDataProcessed) != 0){
                    bananaError("Failed on sem_wait\n");
                    return 0;
                }
                iCount += 10;
            }

        }
        else{
            bananaDebug("Setting exit flag to 1...exiting.\n");
            psBuf->iExitFlag = 1;
            sem_post(&psBuf->semDataReady);
        }

    }
    pthread_join(threadId, NULL);

    sem_destroy(&psBuf->semDataReady);
    sem_destroy(&psBuf->semDataProcessed);
    free(psBuf);

}

void *workerThread(void *psBuffer){

    SHAREDBUFFER *psBuf = (SHAREDBUFFER*) psBuffer;

    FILE *pFile = NULL;
    pFile = fopen("threads.txt", "a");
    if (pFile == NULL){
        bananaError("Failed to open file!\n");
        return NULL;
    }

    while (psBuf->iExitFlag == 0){

        if (sem_wait(&psBuf->semDataReady) != 0){
            bananaError("Failed on sem_wait in workerThread\n");
            return 0;
        }

        if (psBuf->iExitFlag == 1){
            break;
        }

        fprintf(pFile, "%s", psBuf->cBuf);

        if (sem_post(&psBuf->semDataProcessed) != 0){
            bananaError("Failed on sem_post in workerThread\n");
        }
    }
    fclose(pFile);

    return NULL;
}