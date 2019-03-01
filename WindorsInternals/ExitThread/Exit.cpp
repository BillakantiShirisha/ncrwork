#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<iostream>
#define BUFFERSIZE 30
using namespace std;
DWORD ExitCode = 1;
DWORD WINAPI thread_fun(PVOID lparam)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("i=(%d)\n", i);
		Sleep(1000);
		if (i == 3)
			ExitThread(ExitCode);
	}
	return 0;
}
int main()
{
	DWORD threadId;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, thread_fun, NULL, 0, &threadId);
	if (hThread == NULL)
	{
		printf("Unable to create thread\n");
		getchar();
		return 1;
	}
	BOOL b=GetExitCodeThread(hThread, &ExitCode);
	if (b == 0)
		printf("Failed to exited Thread\n");
	else
		printf("Thread exited successfully\n");
	printf("Exit code of the thread is %d\n", ExitCode);
	WaitForSingleObject(hThread, 5000);
	CloseHandle(hThread);
	getchar();
	return 0;
}