#include "include/myAlloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>


void *myAlloc(const char* pFlags, ...){

    char pType[10];
    char pFlag;

    va_list vaArgumentPointer;

    if (sscanf(pFlags,"%s %c", pType, &pFlag) == 2){
        printf("%s %c\n", pType, pFlag);
    }
    else {
        printf("failed!\n");
    }

    va_start(vaArgumentPointer, pFlags);

    int arg1 = va_arg(vaArgumentPointer, int);
    void *pRet = NULL;
    malloc_by_type(pType,&pRet);

    if(pRet == NULL){
        printf("Failed to allocate memory.\n");
    } else{
        printf("Sucess.\n");
    }

    if (pFlag == 'T'){
        int arg2 = va_arg(vaArgumentPointer, int);
    }

    va_end(vaArgumentPointer);




    return pRet;
}
void malloc_by_type(const char *type_name, void **p) {

    if (strcmp(type_name, "int") == 0) {
        *p = malloc(sizeof(int));
    } else if (strcmp(type_name, "float") == 0) {
         *p = malloc(sizeof(float));
    } else if (strcmp(type_name, "double") == 0) {
         *p = malloc(sizeof(double));
    } else if (strcmp(type_name, "char") == 0) {
         *p = malloc(sizeof(char));
    } else{
        printf("Failed to allocate memory. Not a valid datatype.\n");
    }

}