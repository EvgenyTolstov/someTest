#include "EvryThng.h"

#define BUF_SIZE_W 256*256*8

VOID CatFile(HANDLE hInFile, HANDLE hOutFile)
{
	DWORD nIn, nOut;
	CHAR Buffer[BUF_SIZE_W];

	while (ReadFile(hInFile, Buffer, BUF_SIZE_W, &nIn, NULL) && nIn > 0)
	{
		//WriteFile(hOutFile, Buffer, nIn, &nOut, NULL);
		WriteConsole(hOutFile, Buffer, nIn, &nOut, NULL);
		if (nIn != nOut)
		{
			printf("Error by write: %x\n", GetLastError());
			system("pause");
			return;
		}
	}
}


int main(int argc, char *argv[])
{
	BOOL s;
	DWORD FileIndex = Options(argc, argv, "s", &s);
	HANDLE hInFile;
	HANDLE hOutFile;

	while (FileIndex < argc)
	{
		hInFile = CreateFile(argv[FileIndex], GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hInFile == INVALID_HANDLE_VALUE && !s)
		{
			printf("Coun't open Input File, Error: %x\n", GetLastError());
			system("pause");
			return 0;
		}
		hOutFile = GetStdHandle(STD_OUTPUT_HANDLE);//CreateFile(_T("CONOUT$"),
			//GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		CatFile(hInFile, hOutFile);

		CloseHandle(hInFile);
		CloseHandle(hOutFile);
		FileIndex++;
	}
	system("pause");
	return 0;
}