// list.h: Lession 7, exercise 3
//
//
#ifndef _LIST_H_
#define _LIST_H_

#define OK      0
#define ERROR   1

// The list type:

typedef unsigned char BYTE;

typedef struct _NODE {
   struct _NODE *pNext;
   struct _NODE *pPrev;
   int iSze;
   BYTE byBuf[];
} NODE;

typedef struct _LIST {
    struct _NODE *pHead;
    struct _NODE *pTail;
} LIST;

// Prototypes - functions return OK or ERROR.

int InsertInList (LIST *pList, void *pvData, int iSze);
int AddToList (LIST *pList, void *pvData, int iSze);
int RemoveFromList (LIST *pList, NODE *pToDelete);
void DeleteAll(LIST *pList);
NODE* getNode(LIST *pList, int index);

#endif // ndef _LIST_H
