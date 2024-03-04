#include <time.h>
#include <stdlib.h>
#include <stdio.h>




int fibonacci(unsigned int n){

    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);

}