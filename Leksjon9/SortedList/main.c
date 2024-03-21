
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/sortedList.h"

int main(int argC, char *argv[]){

    NODE *pHead = CreateNode("alfa", 5);

    InsertInList(&pHead, "beta");
    InsertInList(&pHead, "delta");
    InsertInList(&pHead, "charlie");
    InsertInList(&pHead, "charlie");
    InsertInList(&pHead, "foxtrot");
    InsertInList(&pHead, "abra");
    InsertInList(&pHead, "caaaabal");
    InsertInList(&pHead, "aaape");

    PrintList(&pHead);

    DeleteList(&pHead);
}