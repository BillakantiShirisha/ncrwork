//Program to read the contents of the file till EOF
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<iostream>
#define BUFFERSIZE 30
using namespace std;
int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hFile;
	TCHAR buffer[BUFFERSIZE];
	hFile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File doesn't exist. error[%d]"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File is opened\n"));
	DWORD nbr;
	printf("Contents in the file are:\n");
	while (1)
	{
		ZeroMemory(buffer, BUFFERSIZE);
		BOOL ret = ReadFile(hFile, &buffer, BUFFERSIZE, &nbr, NULL);
		if (ret == FALSE)
		{
			_tprintf(_T("can't read,error[%d]"), GetLastError());
			getchar();
			return FALSE;
		}
		else if (nbr == 0)
			break;
			_tprintf(_T("%S"), buffer);
	}
	CloseHandle(hFile);
	getchar();
	return TRUE;
}