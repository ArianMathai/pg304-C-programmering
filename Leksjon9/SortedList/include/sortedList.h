//
// Created by Arian Mathai on 20/03/2024.
//

#ifndef C_I_LINUX_SORTEDLIST_H
#define C_I_LINUX_SORTEDLIST_H

#define OK      0
#define ERROR   1

typedef struct _NODE{
    struct _NODE *pNext;
    char *pszString;
} NODE;

NODE *CreateNode (void *pvData, int iSze);
int InsertInList(NODE **ppHead, char *pStr);
void PrintList(NODE **ppHead);
void DeleteList(NODE **ppHead);


#endif //C_I_LINUX_SORTEDLIST_H
