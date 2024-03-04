#include "stdio.h"
#include "stdlib.h"

#define FALSE 0;
#define TRUE 1;

void swap(unsigned int *ap, unsigned int *bp);

void bubblesort(unsigned int arr[], int n);

void printArray(unsigned int arr[], int n);


int main(int argc, char* argv[]){

    int n = argc - 1;

    if (n < 2){
        printf("number of integer args must be at least 2\n");
        return 1;
    }

    unsigned int arr[n];

    for(int i = 1; i <= n; i++){
        arr[i-1] = atoi(argv[i]);
        //printf("%d\n", arr[i-1]);
    }

    printf("size of array = %d\n", n);

    bubblesort(arr, n);
}

void printArray(unsigned int arr[], int n){
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
}

void bubblesort(unsigned int arr[], int n){

    int i = 0, j = 0;

    int swapped = FALSE;

    for (i = 0; i < n - 1; i++){

        swapped = FALSE;

        for (j = i + 1; j < n; j++){

            printf("Within\n");

            if (arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
                swapped = TRUE;
            }

        }

        if(!swapped){
            break;
        }
    }

    printArray(arr,n);
}

void swap(unsigned int *ap, unsigned int *bp){

    int temp = 0;
    temp = *bp;
    *bp = *ap;
    *ap = temp;

    printf("a = %d\n", *ap);

    printf("b = %d\n", *bp);

}