#include <stdio.h>
#include "include/coolBananaLogger.h"


typedef struct _TGAHEADER{
    char  idlength;
    char  colourmaptype;
    char  datatypecode;
    short int colourmaporigin;
    short int colourmaplength;
    char  colourmapdepth;
    short int x_origin;
    short int y_origin;
    short width;
    short height;
    char  bitsperpixel;
    char  imagedescriptor;
}TGAHEADER;

int main(void){

    FILE *pbFile = fopen("img/sample_img.tga", "rb");

    bananaDebug("testing the debugger!\n");
    TGAHEADER sTgaheader;
    if(pbFile != NULL){
        if(fread(&sTgaheader, sizeof (sTgaheader), 1, pbFile) == 1){
            printf("%d\n", sTgaheader.idlength);
        } else{
            printf("Fail\n");
        }
    }
    else{
        printf("Failed to alloc memory when opening file!\n");
        return -1;
    }

}