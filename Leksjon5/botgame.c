// botgame.c: Lession 5, exercise 4
//
// gcc -std=c11 botgame.c -lncurses -o botgame
//
// -or- make TARGET=botgame
//
// As this program is using ncurses, it will not compile on Windows
// without installing CygWin and lots of fuzz...
//
// Ncurses may or may not exist on your Linux box. If it is not
// run this command to get it "sudo apt-get install libncurses5-dev"
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <stdbool.h>

typedef struct {
    char cArr[3][3];
} BOT;

typedef struct _BOTLIST {
    struct _BOTLIST *psNext;
    BOT sThis;
} BOTLIST;

/// BOT cannot be returned because a struct cannot be returned

void createBot();
void createBotListAtHead(BOTLIST **pHead);
int printBot(BOT bot);
bool playLevel(BOTLIST *pRoom, int *pHp, int *pTime);


int main (int iArgC, char *apszArgV[])
{

    srand (time(NULL)); // A simple seed to random numbers
    initscr();          // Init ncurses library.

    int hp = 100, time = 10000, levelsPlayed = 0;

    printw("Welcome to the crappy bot game. Your life is 100\n\n");

    while (hp){

        BOTLIST *pHead = NULL; // pointer to first botlist
        int numOfBots = rand() % 7 + 2;
        printw("number of bots this level = %d\n", numOfBots);

        for (int i = 0; i < numOfBots; ++i) {
            createBotListAtHead(&pHead); // create numOfBots amount of bots for this level
        }

        if (playLevel(pHead, &hp, &time)){
            levelsPlayed++;
            time -= 1000; // set time -= 1s for next level
        }
        else{
            while (pHead != NULL) {
                BOTLIST *pTemp = pHead;
                pHead = pHead->psNext;
                free(pTemp);
            }
            printw("GAME OVER!");
            return 0;
        }
        // Free memory allocated for the room (at pHead)
        while (pHead != NULL) {
            BOTLIST *pTemp = pHead;
            pHead = pHead->psNext;
            free(pTemp);
        }
    }

    endwin();
    return 0;
}
bool playLevel(BOTLIST *pHead, int *pHp, int *pTime){
    int input = 0;
    while (pHead){
        system("clear");
        int sum = printBot(pHead->sThis); // returns number of 1´s int the bot
        printw("Kill bot by typing the number of 1´s!\n");
        timeout (*pTime);  // This is how you do a timed-input. In milliseconds
        input = getch() - '0'; // And just normal input - it gives -1 if the input is timeout
        if (input == sum){
            printw("\nYou killed the bot!\n");
        }
        else if(input == -49){
            printw("\nTimeout! You lost 10 hp!\n");
            *pHp -= 10;
        }
        else{
            *pHp -= 5;
            printw("\nYou lost 5 hp!\n");
        }
        timeout(2000);
        getch();
        pHead = pHead->psNext;
    }
    if (pHead->psNext == NULL){
        printw("Next level\n");
        return TRUE;
    }
    return FALSE;
}

void createBotListAtHead(BOTLIST **pHead){

    BOTLIST *pNewHead = (BOTLIST*) malloc(sizeof(BOTLIST));
    if (pNewHead == NULL){
        printw("Malloc for botlist failed!\n");
        exit(EXIT_FAILURE);
    }

    createBot(&(pNewHead->sThis));

    pNewHead->psNext = *pHead;

    *pHead = pNewHead;

}

void createBot(BOT* pBot){

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int binary = rand() % 2;
            if (binary == 1){
                pBot->cArr[i][j] = '1';
            }
            else{
                pBot->cArr[i][j] = '0';
            }

        }
    }

}

int printBot(BOT bot){ // Returns number of 1s in the bot
    int sum = 0;
    printw("\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printw("%c", bot.cArr[i][j]);
            if (bot.cArr[i][j] == '1'){
                sum++;
            }
        }
        printw("\n");
    }
    printw("\n");
    return sum;
}