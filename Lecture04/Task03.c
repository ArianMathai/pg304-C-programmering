#include "stdio.h"

int main(int argc, char* argv[]){

    int a, b;
    int *p, *q;
    p = &a;
    q = &b;
    printf("Type two integers seperated with space\n");
    scanf("%d %d", p, q);
    printf("The numbers are %d, %d \n", a, b);

    printf(" address of a is %p \n",p);

}