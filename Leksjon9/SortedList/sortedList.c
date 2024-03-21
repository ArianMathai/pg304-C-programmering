
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/sortedList.h"

// A singly Linked that sorts strings on insertion

NODE *CreateNode(void *pvData, int iSze) {
    NODE *pThis = malloc(sizeof(NODE));
    if (pThis != NULL) {
        memset(pThis, 0, sizeof(NODE));
        pThis->pszString = malloc(iSze);
        if (pThis->pszString) {
            memcpy(pThis->pszString, pvData, iSze);
        }
        else {
            free(pThis);
            return NULL;
        }
    }
    return pThis;
}

int InsertInList(NODE **ppHead, char *pStr){

    int iRc = ERROR;

    int size = strlen(pStr);

    NODE *pNewNode = CreateNode(pStr, size);

    if(pNewNode == NULL){
        return iRc;
    }
    if (*ppHead == NULL){
        *ppHead = pNewNode;
        pNewNode->pNext = NULL;
        return iRc = OK;
    }
    NODE *pCur = *ppHead;

    if (strcmp((*ppHead)->pszString, pNewNode->pszString) > 0){
        pNewNode->pNext = *ppHead;
        *ppHead = pNewNode;
        return OK;
    }

    while(pCur){

        if (pCur->pNext == NULL){
            pCur->pNext = pNewNode;
            pNewNode->pNext = NULL;
            iRc = OK;
            break;
        }
        // if str1 > str2, iComp > 0
        int iComp = strcmp(pCur->pNext->pszString, pNewNode->pszString);

        if (iComp >= 0){
            // Put before current
            NODE *pTmp = pCur->pNext;
            pCur->pNext = pNewNode;
            pNewNode->pNext = pTmp;
            iRc = OK;
            break;
        }
        else{
            // newNode is greater than current
            // go next
            pCur = pCur->pNext;
        }

    }
    return iRc;
}

void PrintList(NODE **ppHead){

    NODE *pCur = *ppHead;
    int i = 1;
    while (pCur){
        printf("%d: %s\n", i, pCur->pszString);
        i++;
        pCur = pCur->pNext;
    }
}

void DeleteList(NODE **ppHead){

    NODE *pCur = *ppHead;

    while (pCur){
        NODE *pTmp = pCur;
        pCur = pCur->pNext;
        free(pTmp->pszString);
        free(pTmp);
    }

    *ppHead = NULL;
}



