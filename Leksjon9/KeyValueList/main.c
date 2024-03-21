#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/keyValueList.h"

#define MAX_LINE 256

int main(int argC, char *argv[]){

    FILE *pFile = NULL;
    NODE *pHead = NULL;

    pFile = fopen("keyValFile", "r");

    if (pFile == NULL){
        printf("Error opening file!\n");
        return ERROR;
    }

    char cBuff[MAX_LINE];

    while (fgets(cBuff, sizeof (cBuff), pFile)){

        char *pEquals = strchr(cBuff, '=');
        char *pKey = NULL;
        char *pVal = NULL;

        if (pEquals != NULL){
            int keyLength = pEquals - cBuff;
            if (keyLength > MAX_KEY){ // check if keyLength is more than 32
                printf("keyLength is to long %d\n", keyLength);
                fclose(pFile);
                return ERROR;
            }
            pKey = malloc(keyLength + 1); // +1 for 0 terminator
            if (pKey == NULL) {
                free(pKey);
                fclose(pFile);
                return ERROR;
            }
            strncpy(pKey, cBuff, keyLength);
            pKey[keyLength] = '\0';

            int valLength = strlen(pEquals + 1);
            pVal = malloc(valLength + 1);
            if (pVal == NULL){
                free(pVal);
                free(pKey);
                fclose(pFile);
                return ERROR;
            }
            strncpy(pVal, pEquals + 1, valLength);
            pVal[valLength] = '\0';

            int iRc = InsertSorted(&pHead, pKey, pVal, keyLength, valLength);
            if (iRc == ERROR){
                return ERROR;
            }

            free(pKey);
            free(pVal);
        }

    }
    PrintList(pHead);
    NODE *pNode = Lookup(&pHead, "age");
    if (pNode != NULL){
        printf("Looking up\n");
        PrintNode(pNode);
    }
    int deleteResult = DeleteOnKey(&pHead, "name");
    if (deleteResult == ERROR){
        printf("Failed to delete\n");
    }
    else{
        printf("Printing after delete\n\n");
        PrintList(pHead);
    }


    return 0;
}