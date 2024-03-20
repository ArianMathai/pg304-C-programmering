//
// Created by Arian Mathai on 07/03/2024.
//
#include <semaphore.h>

#ifndef C_I_LINUX_THREADBUF_H
#define C_I_LINUX_THREADBUF_H

typedef struct _SHAREDBUFFER{
    char cBuf[11];
    int iExitFlag;
    sem_t semDataReady;
    sem_t semDataProcessed;
} SHAREDBUFFER;

void *workerThread(void *psBuf);

#endif //C_I_LINUX_THREADBUF_H
