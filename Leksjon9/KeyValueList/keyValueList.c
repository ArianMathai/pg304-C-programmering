#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/keyValueList.h"


NODE *CreateNode(char *pKey, char *pVal, int keyLength, int valLength){

    NODE *pThis = malloc(sizeof (NODE));
    if (pThis != NULL){
        memset(pThis, 0, sizeof (NODE));

        strncpy(pThis->szKey, pKey, keyLength);

        if (pVal[0] == '"'){
            pThis->pszValue = malloc(sizeof (char ) * valLength);
            if (pThis->pszValue != NULL){
                strncpy(pThis->pszValue, pVal, valLength);
            }
            else{
                free(pThis);
                return NULL;
            }
        }
        else{
            pThis->iValue = atoi(pVal);
        }
    }
    return pThis;
}

int InsertSorted(NODE **ppHead, char *pKey, char *pVal, int keyLength, int valLength){
    int iRc = ERROR;

    NODE *pNewNode = CreateNode(pKey, pVal, keyLength, valLength);
    if (pNewNode != NULL){
        if (*ppHead == NULL){
            *ppHead = pNewNode;
            return iRc = OK;
        } else{
            NODE *pCur = *ppHead;
            if (strcmp((*ppHead)->szKey, pNewNode->szKey) > 0){
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
                int iComp = strcmp(pCur->pNext->szKey, pNewNode->szKey);

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
        }
    }
    return iRc;
}
NODE *Lookup(NODE **ppHead, char *pStr){

    if (*ppHead != NULL){
        NODE *pCur = *ppHead;
        while (pCur){
            if (strcmp(pCur->szKey, pStr) == 0){
                return pCur;
            }
            pCur = pCur->pNext;
        }
    }
    return NULL;
}
int DeleteOnKey(NODE **ppHead, char *pStr){

    int iRc = ERROR;
    if (*ppHead == NULL){
        return iRc;
    }
    NODE *pToDelete = Lookup(ppHead, pStr);
    NODE *pCur = *ppHead;

    if (pToDelete != NULL){

        if (pToDelete == *ppHead){
            NODE *pTmp = *ppHead;
            *ppHead = (*ppHead)->pNext;
            if (pTmp->pszValue != NULL){
                free(pTmp->pszValue);
            }
            free(pTmp);
            return OK;
        }

        while (pCur){

            if (pToDelete == pCur->pNext){
                NODE *pTmp = pCur->pNext;
                pCur->pNext = pTmp->pNext;
                if (pTmp->pszValue){
                    free(pTmp->pszValue);
                }
                free(pTmp);
                iRc = OK;
                break;
            }
            pCur = pCur->pNext;
        }
    }

    return iRc;

}
void PrintNode(NODE *pThis){
    if (pThis != NULL){
        if (pThis->pszValue != NULL){
            printf("%s = %s\n", pThis->szKey, pThis->pszValue);
        }
        else{
            printf("%s = %d\n", pThis->szKey, pThis->iValue);
        }
    }
}
void PrintList(NODE *pHead){
    NODE *pCur = pHead;
    if (pHead != NULL){
        while (pCur){
            PrintNode(pCur);
            pCur = pCur->pNext;
        }
    }
}

