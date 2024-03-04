#include <stdlib.h>
#include "stdio.h"

int main(int argC, char **argv){

    FILE *pfb, *pft;

    pft = fopen("doubles.txt", "r");
    if (pft != NULL){
        pfb = fopen("doubles.dat", "wb");
        if (pfb != NULL){
            double value;
            while(fscanf(pft, "%lf", &value) == 1){
                fwrite(&value, sizeof(double), 1, pfb);
            }
            fclose(pfb);
        }
        fclose(pft);
    }

    pft = NULL;

    pfb = fopen("doubles.dat", "rb");
    if (pfb != NULL){
        pft = fopen("doublesRead.txt", "w");
        if (pft != NULL){
            double val;
            while (!feof(pfb)){
                if (fread(&val, sizeof (double), 1, pfb) == 1){
                    fprintf(pft, "%lf", val);
                    fprintf(pft, "\n");
                }
            }
            fclose(pft);
        }
        fclose(pfb);
    }
}

