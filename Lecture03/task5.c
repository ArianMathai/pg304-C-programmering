#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int IsPrime(unsigned int num);

void task5(){
    srand(time(NULL));

    int a = rand()%20;
    printf("a is %d\n", a);

    int solved = IsPrime(a);

    switch (solved) {
        case 0:
            printf("%d is not a prime", a);
            break;
        case 1:
            printf("%d is a prime", a);
            break;
    }
}


int IsPrime(unsigned int num) {

    if (num < 2){
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if ((num % i) == 0){
            return 0;
        }
    }
    return 1;
}

