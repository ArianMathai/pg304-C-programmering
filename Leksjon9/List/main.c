#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/list.h"


void PrintList (LIST *pList);

int main(int argC, char *argv[]){

    LIST myList;
    myList.pHead = NULL;
    myList.pTail = NULL;



    InsertInList(&myList, "first", 6);
    InsertInList(&myList, "second", 7);
    InsertInList(&myList, "third", 6);
    AddToList(&myList, "last", 5);
    AddToList(&myList, "llast", 6);

    PrintList(&myList);

    NODE *pCur = getNode(&myList, 1);

    RemoveFromList(&myList, pCur);
    printf("Deleted node 'first'\n");
    PrintList(&myList);

    DeleteAll(&myList);



}
void PrintList (LIST *pThis)
{
    NODE *pCur = pThis->pHead;

    int i = 0;
    while (pCur != NULL) {
        printf ("%d: %s\n", ++i, pCur->byBuf);
        pCur = pCur->pNext;
    }
    printf ("\n");
}