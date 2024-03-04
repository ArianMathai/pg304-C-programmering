#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int intInput();
void bubblesort(int arr[], int n);
void swap(int *pA, int *pB);
int isFull(int *arr, int size);

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("give two args\n");
        return 1;
    }

    int rows = 0, cols = 0;


    rows = atoi(argv[1]); // rows = args 1
    cols = atoi(argv[2]); // cols = args 2

    int **array = NULL; // = array[][]

    array = (int**) malloc(rows * sizeof(int *));//allocate memory for rows

    for (int i = 0; i < rows; ++i) {
        array[i] = (int*) malloc(cols * sizeof(int)); //allocate memory for cols
    }


    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = -1;
        }
    }

   // memset(array, 0, rows * sizeof (int*)); // set all rows to 0



    time_t t;
    srand((unsigned) time(&t)); // init rand

    int count = 0;
    while (count < cols*rows){

        int row = rand() % rows;

        int full = isFull(array[row], cols);

        if (full == FALSE){
            count++;
            continue;
        }
    }

    int k;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            k = array[i][j];
            printf("element of array[%d][%d] = %d\n", i, j, k);
        }
    }

    printf("WOOW, that dosent look sorted. Lets bubble it boooi\n");

    for (int i = 0; i < rows; ++i) {
        bubblesort(array[i], cols);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            k = array[i][j];
            printf("element of array[%d][%d] = %d\n", i, j, k);
        }
    }




    for (int i = 0; i < rows; ++i) {
        free(array[i]);
    }
    free(array);

    return 0;

}

int isFull(int arr[], int size){
    int i = 0;
    while (i < size){
        if (arr[i] == -1){
            arr[i] = intInput();
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

int intInput(){
    int num = 0;

    printf("Hey frien, input an Integer\n");
    scanf("%d",&num);

    return num;
}

void bubblesort(int arr[], int n){

    int i;

    int swapped = TRUE;

    while(swapped){

        swapped = FALSE;

        for (i = 1; i < n; i++){

            if (arr[i - 1] > arr[i]){
                swap(&arr[i - 1], &arr[i]);
                swapped = TRUE;
            }
        }

    }

}

void swap(int *pA, int *pB){

    int pTemp = *pA;
    *pA = *pB;
    *pB = pTemp;
}
