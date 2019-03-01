#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<iostream>
#define BUFFERSIZE 30
using namespace std;
DWORD WINAPI thread_fun(PVOID lparam)
{
	int i;
	for (i = 0; i < 1001; i++)
	{
		printf("i=(%d)\n", i);
		//Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD threadId;
	HANDLE hThread;
	HANDLE arryHand[2];
	hThread = CreateThread(NULL, 0, thread_fun, NULL, CREATE_SUSPENDED, &threadId);
	if (hThread == NULL)
	{
		printf("Unable to create thread\n");
		getchar();
		return 1;
	}
	else
	{
		Sleep(5000);
		ResumeThread(hThread);
	}
	WaitForSingleObject(hThread, 5000);
	printf("Thread Completed");
	CloseHandle(hThread);
	getchar();
	return 0;
}