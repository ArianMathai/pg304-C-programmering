#include "include/coolBananaLogger.h"
#include <stdio.h>

int main(void){

    coolBananaLogger(666,__LINE__, __FILE__, "Hei hei");
    for (int i = 0; i < 4; ++i) {
        coolBananaLogger(i,__LINE__, __FILE__, "Hva skjer?");
    }
    coolBananaLogger(555, __LINE__,__FILE__,"Seeya!");
    bananaDebug("This is a debug test");
    bananaError("This is an error test");


    return 0;
}