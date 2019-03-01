#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<tchar.h>
#include<iostream>
using namespace std;
#define BUFFERSIZE 100
int _tmain(int argc, TCHAR* argv[])
{
	DWORD nbr;
	TCHAR buff[BUFFERSIZE];
	ZeroMemory(buff, sizeof(buff));
	BOOL ret = ReadFile(argv[1], buff, BUFFERSIZE, &nbr, NULL);
	if (ret == 0)
	{
		_tprintf(_T("Cant read file Error %d\n"), GetLastError());
		getchar();
		return -1;
	}
	CloseHandle(argv[1]);
	getchar();
	return 0;
}