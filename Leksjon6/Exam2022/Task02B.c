#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int withinRange(char c){
    if ((int) c > 96 && (int) c < 123){
        return TRUE;
    }
    return FALSE;
}

void main(void){

    FILE *ptFile = NULL;
    char *pBuffer = NULL;
    long fileSize = 0, bytesRead;

    int letterCounter[26];

    memset(letterCounter, 0, sizeof(letterCounter));


    ptFile = fopen("Exam2022/outputText.txt", "r");

    if (ptFile != NULL){
        if (fseek(ptFile, 0, SEEK_END) == 0){
            fileSize = ftell(ptFile);
            rewind(ptFile);

            pBuffer = malloc(fileSize + 1);

            if (pBuffer != NULL){
                bytesRead = fread(pBuffer, sizeof (char), fileSize, ptFile);
                if (bytesRead == fileSize){
                    printf ("%ld bytes read.\n", bytesRead);
                } else{
                    printf("Failed to read file");
                }
            }
        }
        fclose(ptFile);
    }
    for (int i = 0; i < fileSize; ++i) {
        if (pBuffer != NULL){
            pBuffer[i] = tolower(pBuffer[i]);
            //printf("%c", pBuffer[i]);
        }
    }
    int num = 0;
    for (int i = 0; i < fileSize; ++i) {
        if (pBuffer != NULL){
            if (withinRange(pBuffer[i])){
                num = pBuffer[i] - 'a';
                //printf("num is %d, char is %c\n", num, pBuffer[i]);
                ++letterCounter[num];
            }
            //printf("Not within range on loop nr %d\n", i);
        }
    }

    for (int i = 0; i < 26; ++i) {
        printf("Letter %c = ", (char) i + 97);
        printf("%d number of times\n", letterCounter[i]);
    }

    free(pBuffer);

}

