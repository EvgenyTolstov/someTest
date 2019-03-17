//#define UNICODE  // Set by Self
#undef UNICODE  

#ifdef UNICODE
#define _UNICODE
#else
#undef _UNICODE
#endif

#include <windows.h>
#include <tchar.h>	
#include <stdio.h>
#include <io.h>
#include <stdlib.h>

// from Support.h
#define YES _T("y")
#define CR 0x0D
#define LF 0x0A
#define TSIZE sizeof(TCHAR)
#define MAX_OPTIONS 20
#define TYPE_FILE 1
#define TYPE_DIR 2
#define TYPE_DOT 3

BOOL PrintStrings(HANDLE hOut, ...);
BOOL PrintMsg(HANDLE hOut, LPCTSTR pMsg);
BOOL ConsolePrompt(LPCTSTR pPromptMsg, LPTSTR pResponse, DWORD MaxTchar, BOOL Echo);
VOID ReportError(LPCTSTR UserMessage, DWORD ExitCode, BOOL PrintErrorMsg);
DWORD Options(int argc, LPTSTR argv[], LPCTSTR OptStr, ...);
BOOL Asc2Un(LPCTSTR fIn, LPCTSTR fOut, BOOL bFailIfExists);
VOID ReportException(LPCTSTR UserMessage, DWORD ExcetionCode);

#ifdef _UNICODE
#define _memtchr wmemchr
#else
#define _memtchr memchr
#endif

