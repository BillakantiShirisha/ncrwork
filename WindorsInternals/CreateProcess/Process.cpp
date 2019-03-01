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
	printf("Current Process ID is %ld\n", GetCurrentProcessId());
	printf("Current Thread ID is %ld\n", GetCurrentThreadId());
	printf("Process ID is %ld\n", GetProcessId(pi.hProcess));
	printf("Thread ID is %ld\n", GetThreadId(pi.hThread));
	printf("Process ID of Thread is %ld\n", GetProcessIdOfThread(pi.hThread));
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
	printf("Current Process ID is %ld\n", GetCurrentProcessId());
	printf("Current Thread ID is %ld\n", GetCurrentThreadId());
	printf("Process ID is %ld\n", GetProcessId(pi.hProcess));
	printf("Thread ID is %ld\n", GetThreadId(pi.hThread));
	printf("Process ID of Thread is %ld\n", GetProcessIdOfThread(pi.hThread));
	cout << endl;
	delete lps;
	getchar();
	return 0;
}