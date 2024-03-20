#include "include/myAlloc.h"
#include <stdlib.h>

int main(int argC, char *argv[]){

    void *p = NULL;

    p = myAlloc("int T", 1, 2147483647); // highest int value 2147483647;

    free(p);

}