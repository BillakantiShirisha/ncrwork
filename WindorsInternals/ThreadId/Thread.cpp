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
		printf("i=(%d)\n",i);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD threadId;
	HANDLE hThread;
	HANDLE arryHand[2];
	hThread = CreateThread(NULL, 0, thread_fun, NULL, 0, &threadId);
	if (hThread == NULL)
	{
		printf("Unable to create thread\n");
		getchar();
		return 1;
	}
	CloseHandle(hThread);
	getchar();
	return 0;
}