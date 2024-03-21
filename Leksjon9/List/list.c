// list.c: Lession 7, exercise 3 (Lession 9 / Example)
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/list.h"

NODE *CreateNode (void *pvData, int iSze)
{
   NODE *pThis = malloc (sizeof(NODE) + iSze);
   if (pThis != NULL) {
      memset (pThis, 0, sizeof(NODE) + iSze);
      pThis->iSze = iSze;
      memcpy (pThis->byBuf, pvData, iSze);
   }
   return pThis;
}


int InsertInList (LIST *pList, void *pvData, int iSze)
{
    int iRc = ERROR;
    NODE *pThis = CreateNode (pvData, iSze);

    if (pThis == NULL){
        return iRc;
    }
    // if list is empty
    if (pList->pHead == NULL){
        pList->pHead = pThis;
        pList->pTail = pThis;
        pThis->pNext = NULL;
        pThis->pPrev = NULL;
        iRc = OK;
    }
    else{
        pList->pHead->pPrev = pThis;
        pThis->pNext = pList->pHead;
        pList->pHead = pThis;
        pList->pHead->pPrev = NULL;
        iRc = OK;
    }

    return iRc;

}

int AddToList (LIST *pList, void *pvData, int iSze)
{
    int iRc = ERROR;
    NODE *pThis = CreateNode (pvData, iSze);

    if (pThis == NULL){
        return iRc;
    }
    if (pList->pTail == NULL){
        pList->pHead = pThis;
        pList->pTail = pThis;
        pThis->pNext = NULL;
        pThis->pPrev = NULL;
    }
    else{
        pList->pTail->pNext = pThis;
        pThis->pPrev = pList->pTail;
        pList->pTail = pThis;
        pList->pTail->pNext = NULL;
        iRc = OK;
    }

    return iRc;
}

int RemoveFromList (LIST *pList, NODE *pToDelete)
{
    int iRc = ERROR;
    NODE *pThis = NULL;

    if (pList->pHead == pToDelete) {
        if (pList->pHead->pNext == NULL){
            pList->pTail = NULL;
        }
        pList->pHead = pToDelete->pNext;
        iRc = OK;
    }
    else{
        pThis = pList->pHead;
        while (pThis){
            if (pThis->pNext == pToDelete){
                pThis->pNext = pToDelete->pNext;
                pToDelete->pNext->pPrev = pThis;
                iRc = OK;
                break;
            }
            pThis = pThis->pNext;
        }
    }
    if (iRc == OK){
        free(pToDelete);
    }
    return iRc;

  /*
   else {
      pThis = *ppHead;
      while (pThis != NULL) {
         if (pThis == pToDelete) {
            pPrev->pNext = pThis->pNext;
            iRc = OK;
            break;
         }
         pPrev = pThis;
         pThis = pThis->pNext;
      }
   }
   if (iRc == OK) free (pToDelete);
   return iRc;
   */
}

void DeleteAll(LIST *pList){

    NODE *pCur = NULL;

    pCur = pList->pHead;


    while (pCur){
        NODE *pTmp = pCur;
        pCur = pCur->pNext;
        free(pTmp);
    }
    pList->pHead = NULL;
    pList->pTail = NULL;
    printf("List deleted");

}
NODE* getNode(LIST *pList, int index){

    NODE *pThis = pList->pHead;

    for (int i = 1; i < index; ++i) {
        pThis = pThis->pNext;
    }

    return pThis;
}
