//
// Created by Arian Mathai on 20/03/2024.
//

#ifndef C_I_LINUX_KEYVALUELIST_H
#define C_I_LINUX_KEYVALUELIST_H

#define OK      0
#define ERROR   1

#define MAX_KEY 32

typedef struct _NODE {
    struct _NODE *pNext;
    char szKey[MAX_KEY];
    char *pszValue;
    int  iValue;
} NODE;


NODE *CreateNode(char *pKey, char *pVal, int keyLength, int valLength);
void PrintNode(NODE *pThis);
void PrintList(NODE *pHead);
int InsertSorted(NODE **ppHead, char *pKey, char *pVal, int keyLength, int valLength);
NODE *Lookup(NODE **ppHead, char *pStr);
int DeleteOnKey(NODE **ppHead, char *pStr);

#endif //C_I_LINUX_KEYVALUELIST_H
