#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void main(void){

    FILE *ptFile;
    long fileSize = 0, bytesRead;
    char *pBuffer = NULL;

    char word[50];
    printf("Enter a word: \n");
    fgets(word, sizeof (word), stdin); // safe from buffer overflow ish
    printf("%s\n", word);

    ptFile = fopen("adventures.txt", "r");

    if (ptFile != NULL){
        if (fseek(ptFile, 0, SEEK_END) == 0){
            fileSize = ftell(ptFile);
            printf("Filesize = %ld\n", fileSize);
            rewind(ptFile);

            pBuffer = malloc(fileSize + 1); // +1 for zero termination
            if (pBuffer != NULL){
                bytesRead = fread(pBuffer, sizeof (char), fileSize, ptFile);
                if (bytesRead == fileSize){
                    printf ("%ld bytes read.\n", bytesRead);
                    for (int i = 0; i < bytesRead; i++) {
                        printf("%c", pBuffer[i]);
                    }
                    printf("\n");
                }
            }
        }
        fclose(ptFile);
    }

    int *pIndex;
    int size = sizeof (word) * 4;
    pIndex = malloc( size);
    int count = sizeof (word);
    if (pIndex != NULL){
        if (pBuffer != NULL){
            int j = 0;
            for (int i = 0; i < fileSize; ++i) {
                if (pBuffer[i] == word[j]){
                    pIndex[j] = i;
                    i += 10;
                    j++;
                    if (j == count){
                        printf("test");
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        printf("Index = %d \n", pIndex[i]);
    }

    free(pIndex);
    free(pBuffer);
}