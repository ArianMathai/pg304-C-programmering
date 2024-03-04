#include <stdio.h>
#include <stdlib.h>
#include "include/myLinkedList.h"
#include "include/coolBananaLogger.h"


void insertAtHead(NODE **ppsHead, int iDta){

    NODE *psNewHead = NULL;

    psNewHead = (NODE*) malloc( sizeof(NODE));

    if (psNewHead != NULL){
        psNewHead->iData = iDta;
        psNewHead->psNext = *ppsHead;
        *ppsHead = psNewHead;
        bananaDebug("All is good\n");

    } else{
        printf("Failed to malloc memory in insetion at head!\n");
        bananaError("Failed to malloc memory in insertion at head!\n");
        free(psNewHead);
    }
}
void insertAtTail(NODE **ppsHead, int iDta){

    NODE *psNewTail = NULL;

    psNewTail = (NODE*) malloc(sizeof (NODE));

    if (psNewTail == NULL) {
        printf("Failed to allocate memory for new tail node!\n");
        return;
    }

    psNewTail->iData = iDta;
    psNewTail->psNext = NULL;

    if (*ppsHead == NULL){
        *ppsHead = psNewTail;
    } else {
        NODE *psTmp = *ppsHead;
        while (psTmp->psNext != NULL){
            psTmp = psTmp->psNext;
        }
        psTmp->psNext = psNewTail;
    }
}
void freeNode(NODE **ppsHead){
    if (*ppsHead == NULL){
        printf("No node to free\n");
        return;
    }
    NODE *psTmp = *ppsHead;
    *ppsHead = (*ppsHead)->psNext;
    free(psTmp);
}
void printList(NODE *pHead){

    if (pHead == NULL){
        printf("List is empty!\n");
    }

    int i = 0;

    while (pHead != NULL){
        printf("Node element %d == %d\n", i, pHead->iData);
        pHead = pHead->psNext;
        i++;
    }
}