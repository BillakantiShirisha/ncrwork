#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<tchar.h>
#include<iostream>
using namespace std;
#define BUFFERSIZE 100
int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (!CreateProcess(
		_T("Source1.exe"),
		NULL,
		NULL,
		NULL,
		FALSE,
		HIGH_PRIORITY_CLASS,
		NULL,
		NULL,
		&si,
		&pi
	))
	{
		printf("Create process error %d\n", GetLastError());
		getchar();
		return 0;
	}
	getchar();
	return 0;
}