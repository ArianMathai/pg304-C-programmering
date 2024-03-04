
#include "include/myLinkedList.h"
#include <stdlib.h>

int main(void){

    NODE *psHead = NULL;

    for (int i = 0; i < 3; ++i) {
        insertAtHead(&psHead, i);
    }

    insertAtTail(&psHead, 20);
    printList(psHead);

    while (psHead != NULL){
        freeNode(&psHead);
    }
    printList(psHead);



    return 0;

}