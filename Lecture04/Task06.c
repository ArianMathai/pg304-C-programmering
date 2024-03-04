#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#define FALSE 0;
#define TRUE 1;

void swap(char **PPA, char **PPB);

void bubblesort(char *cp[], int n);

void printArray(char *arr[], int n);


int main(int argc, char* argv[]){

    int n = argc - 1;

    if (n < 2){
        printf("number of args must be at least 2\n");
        return 1;
    }

    bubblesort(&argv[1], n);
}

void printArray(char *argv[], int n){
    for (int i = 0; i < n; ++i) {
        printf("%s\n", argv[i]);
    }
}

void bubblesort(char *argv[], int n){

    int i , j;

    int swapped = FALSE;

    for (i = 0; i < n - 1; i++){

        swapped = FALSE;

        for (j = 0; j < n - i - 1; j++){

            if (strcmp(argv[j], argv[j + 1]) > 0){
                swap(&argv[j], &argv[j+1]);
                swapped = TRUE;
            }
        }
        if(!swapped){
            break;
        }
    }

    printArray(argv,n);
}

void swap(char **PPA, char **PPB){


    char *pTemp = *PPA;
    *PPA = *PPB;
    *PPB = pTemp;

}