#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<iostream>
#define BUFFERSIZE 30
using namespace std;
DWORD WINAPI thread_fun(PVOID lparam)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("i=(%d)\n", i);
		Sleep(1000);
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
	WaitForSingleObject(hThread, 5000);
	DWORD ExitCode=1;
	BOOL b=TerminateThread(hThread, ExitCode);
	if (b == 0)
		printf("Failed to Terminate Thread\n");
	else
		printf("Thread Terminated successfully\n");
	GetExitCodeThread(hThread, &ExitCode);
	printf("Exit code of the thread is %d\n",ExitCode);
	CloseHandle(hThread);
	getchar();
	return 0;
}