#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>


int fibonacci(unsigned int n);
int quickFibIterative(int n);
unsigned long GetTime();

int main(int argc, char *argv[]){

    unsigned long timeStart, timeEnd;
    timeStart = GetTime();
    printf("TimeStart %lu\n", timeStart);

    int fib = fibonacci(30);
    printf("fibonacci = %d\n", fib);
    int qfib = quickFibIterative(30);
    printf("quick fibonacci = %d\n", qfib);
    timeEnd = GetTime();
    printf("TimeEnd %lu\n", timeEnd);
    printf("The elapsed time is %lu ms", (timeEnd - timeStart)/1000);

}

int fibonacci(unsigned int n){

    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);

}

int quickFibIterative(int n){

    int a=1, b=1, c;

    if (n == 0) {
        return 0;
    }
    if (n == 1){
        return 1;
    }

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

unsigned long GetTime() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*(unsigned long)1000000+tv.tv_usec;
}


