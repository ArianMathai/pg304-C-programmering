#include "./include/coolBananaLogger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>


void coolBananaLogger(unsigned long ulErrorType, int iLine, const char *szFile, const char *pszFormat, ...){

    static FILE *ptLogFile = NULL;

    static int iCounter = 1;

    va_list vaArgumentPointer;
    char szOutputString[256] = {0};

    char szFileName[256] = {0};
    time_t tTimeAndDate = 0;
    const char *pszType = (ulErrorType == 1) ? "Error": "Debug";

    if(ptLogFile == NULL){
        tTimeAndDate = time(NULL);
        snprintf(szFileName, 256 - 1, "./loggerFiles/debug_%li.txt", tTimeAndDate);
        ptLogFile = fopen(szFileName, "a");
    }

    va_start(vaArgumentPointer, pszFormat);
    vsnprintf(szOutputString, 256-1, pszFormat, vaArgumentPointer);
    va_end(vaArgumentPointer);

    if(ptLogFile != NULL){
        fprintf(ptLogFile, "%04d: %s in file: %s, on line: %d = %s \n", iCounter++, pszType, szFile,iLine, szOutputString);
    }


}



