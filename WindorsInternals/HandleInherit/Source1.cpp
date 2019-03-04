#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<tchar.h>
#include<iostream>
using namespace std;
#define BUFFERSIZE 100
int main(int argc, CHAR* argv[])
{
	//cout << "Hello ";
	DWORD nbr;
	TCHAR buff[BUFFERSIZE];
	ZeroMemory(buff, BUFFERSIZE);
	int i = atoi(argv[0]);
	HANDLE hFile = (HANDLE)i;
	_tprintf(_T("Handle value in Source1 = %s\n"), argv[0]);
	printf("Handle value in Source1 = %d\n", hFile);
	//HANDLE hFile1;

	BOOL ret = ReadFile(hFile, buff, BUFFERSIZE, &nbr, NULL);
	if (ret == FALSE)
	{
		_tprintf(_T("Cant read file Error %d\n"), GetLastError());
		getchar();
		return -1;
	}
	cout << nbr << endl;
	_tprintf(_T("Text is %s"), buff);
	//CloseHandle(hFile);
	CloseHandle(hFile);
	getchar();
	return 0;
}