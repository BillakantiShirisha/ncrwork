//Program to read the contents of the file
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
	if (argc != 2)
	{
		_tprintf(_T("Usage fileopen.exe <name of the file>\n"));
		getchar();
		return FALSE;
	}
	hFile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File doesn't exist. error[%d]"),GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File is opened\n"));
	ZeroMemory(buffer, BUFFERSIZE);
	DWORD nbr;
	BOOL ret = ReadFile(hFile, buffer, BUFFERSIZE, &nbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("can't read,error[%d]"), GetLastError());
		getchar();
		return FALSE;
	}
	CloseHandle(hFile);
	_tprintf(_T("Text from (%s) is: %S \n"), argv[1], buffer);
	getchar();
	return TRUE;
}