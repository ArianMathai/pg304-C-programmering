#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printerWithFor(){
    srand(time(NULL));
    int a = rand()%40;
    int sum = 0;
    for (int i = 39; i >= 0 ; --i) {
        sum = sum + a--;
    }
    printf("sum = %d\n", sum);
}

void printerWithWhile(){
    srand(time(NULL));
    int a = rand()%40;
    int sum = 0;

    while(a>0){
        sum = sum + --a;
    }
    printf("sum = %d\n", sum);
}

void printerWithDoWhile(){
    srand(time(NULL));
    int a = rand()%40;
    int sum = 0;
    do{
        sum = sum + --a;
    }while(a>0);

    printf("sum = %d\n", sum);
}
