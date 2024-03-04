#include <stdio.h>

int a, b;

int main (void)
{
    int i, j;
    printf("Addresses of global variables: %p %p\n", &a, &b);
    printf("Addresses of global variables: %p %p\n", &i, &j);
    return 0;
}