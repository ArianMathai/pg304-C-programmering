#include <stdio.h>
#include <stdlib.h>

int main (int iArgC, char *apszArgV[])
{
    if (iArgC < 2) {
        printf ("Usage: ex4 <string1> <string2> ... <stringN>\n");
        return 1;
    }

    printf ("Number of strings: %d\n", iArgC - 1);

    for (int i = 1; i < iArgC; i++) {
        printf ("%d: %s\n", i, apszArgV[i]);
    }

    return 0;
}
