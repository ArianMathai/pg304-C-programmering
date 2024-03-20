#ifndef __COOL_BANANA_LOGGER_H__
#define __COOL_BANANA_LOGGER_H__

void coolBananaLogger(unsigned long ulErrorType, int iLine, const char *szFile, const char *pszFormat, ...);

//extern int glob_bTraceEnabled;

#define bananaDebug(...) coolBananaLogger(0, __LINE__, __FILE__, __VA_ARGS__)
//#define bananaDebug(...) if (glob_bTraceEnabled == 1) {coolBananaLogger(0, __LINE__, __FILE__, __VA_ARGS__);}
#define bananaError(...) coolBananaLogger(1, __LINE__, __FILE__, __VA_ARGS__)

#endif // __COOL_BANANA_LOGGER_H__