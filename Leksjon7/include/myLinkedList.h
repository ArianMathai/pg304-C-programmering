//
// Created by Arian Mathai on 04/03/2024.
//

#ifndef C_I_LINUX_MYLINKEDLIST_H
#define C_I_LINUX_MYLINKEDLIST_H

typedef struct _NODE {
    struct _NODE *psNext;
    int iData;
} NODE;

void insertAtHead(NODE **ppsHead, int iDta);
void printList(NODE * pHead);
void insertAtTail(NODE **ppsHead, int iDta);
void freeNode(NODE **ppsHead);



#endif //C_I_LINUX_MYLINKEDLIST_H
