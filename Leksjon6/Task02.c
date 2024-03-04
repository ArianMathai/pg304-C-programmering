#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// aeiou - vowels

bool isVowel(int c);
void findTwoVowels(FILE * ptFile, int *pVowelCounter);
void findTwoConsecutiveLetters(FILE *ptFile, int *pLetterCounter);
int main(int argC, char **argv){

    FILE *ptFile;
    long fileSize;
    int vowelCounter = 0;
    int letterCounter = 0;

    ptFile =  fopen("test.txt", "r"); // open file
    if (ptFile != NULL){ // check if it opened
        if (fseek(ptFile, 0, SEEK_END) == 0){
            fileSize = ftell(ptFile); // set size of file in bytes
            printf("The size of the file is %ld\n", fileSize);
            rewind(ptFile); // set file pointer to beginning of file

            findTwoVowels(ptFile, &vowelCounter);
            rewind(ptFile);
            findTwoConsecutiveLetters(ptFile, &letterCounter);

        }
        fclose(ptFile);
    }
}
void findTwoConsecutiveLetters(FILE *ptFile, int *pLetterCounter){
    int prev;
    int next;

    while ((prev = getc(ptFile)) != EOF){
        printf("place of c on loop = %ld\n",  ftell(ptFile));
        if ((next = getc(ptFile)) != EOF && next == prev){
            ++*pLetterCounter;
        }
    }
    printf("amount of two consectuive letters = %d\n", *pLetterCounter);
}

void findTwoVowels(FILE *ptFile, int *pVowelCounter){
    int c;
    int nextChar;
    while ((c = getc(ptFile)) != EOF){
        printf("place of c on loop = %ld\n",  ftell(ptFile));
        if (isVowel(c)){
            nextChar = getc(ptFile);
            if (nextChar != EOF && isVowel(nextChar)){
                ++*pVowelCounter;
            }

        }
        printf("vowelCounter = %d\n", *pVowelCounter);
    }
}
bool isVowel(int c){
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}


