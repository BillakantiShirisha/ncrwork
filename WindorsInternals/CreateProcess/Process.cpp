#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<iostream>
#define BUFFERSIZE 30
using namespace std;
int main()
{
	STARTUPINFO sui;
	PROCESS_INFORMATION pi;
	int proc;
	ZeroMemory(&sui, sizeof(sui));
	sui.cb = sizeof(sui);
	ZeroMemory(&pi, sizeof(pi));
	LPWSTR lps = NULL;
	lps = new WCHAR[100];
	wcscpy_s(lps, _countof(L"notepad"), L"notepad");
	proc = CreateProcess(NULL, lps, NULL, NULL, FALSE, 0, NULL, NULL, &sui, &pi);
	if (proc == 0)
	{
		printf("Error in creating process %d\n", GetLastError());
		getchar();
		return 0;
	}
	printf("Handle of process is %ld\n", pi.hProcess);
	printf("Process  ID of process is %ld\n", pi.dwProcessId);
	printf("Handle of thread is %ld\n", pi.hThread);
	printf("Process ID thread is %ld\n", pi.dwThreadId);
	cout << endl;
	delete lps;
	lps = new WCHAR[100];
	wcscpy_s(lps, _countof(L"calc.exe"), L"calc.exe");
	proc = CreateProcess(NULL, lps, NULL, NULL, FALSE, 0, NULL, NULL, &sui, &pi);
	if (proc == 0)
	{
		printf("Error in creating process %d\n", GetLastError());
		getchar();
		return 0;
	}
	printf("Handle of process is %ld\n", pi.hProcess);
	printf("Process  ID of process is %ld\n", pi.dwProcessId);
	printf("Handle of thread is %ld\n", pi.hThread);
	printf("Process ID thread is %ld\n", pi.dwThreadId);
	cout << endl;
	delete lps;
	getchar();
	return 0;
}