#include<Windows.h>
#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
#define QSIZE 5
SRWLOCK srwLock;
CONDITION_VARIABLE g_cvReadyToProduce;
CONDITION_VARIABLE g_cvReadyToConsume;
struct object
{
	int threadNo;
	int element;
};
queue<object> gSharedQ;
DWORD WINAPI WriteThread(LPVOID lparam)
{
	int threadno = PtrToUlong(lparam);
	for (int ele = 1; ele <= 10; ele++)
	{
		object obj = { threadno,ele };
		AcquireSRWLockExclusive(&srwLock);
		if (gSharedQ.size() >= QSIZE)
		{
			cout << "Write Thread " << threadno << " Queue is full.Can't produce " << ele << "\n";
			SleepConditionVariableSRW(&g_cvReadyToProduce, &srwLock, INFINITE, 0);
		}
		else
		{
			gSharedQ.push(obj);
			cout << "Write thread " << threadno << " Produced " << ele << "\n";
			ReleaseSRWLockExclusive(&srwLock);
			WakeAllConditionVariable(&g_cvReadyToConsume);
			Sleep(1500);
		}
	}
	return 0;
}
DWORD WINAPI ReadThread(LPVOID lparam)
{
	int threadno = PtrToUlong(lparam);
	for (int ele = 1; ele <= 10; ele++)
	{
		//object obj = { threadno,ele };
		AcquireSRWLockShared(&srwLock);
		if (gSharedQ.size() <= 0)
		{
			cout << "Read thread can't read.Queue is empty\n";
			SleepConditionVariableSRW(&g_cvReadyToConsume, &srwLock, INFINITE, 0);
		}
		else
		{
			object obj = gSharedQ.front();
			cout << "Reader thread consumed\n";
			gSharedQ.pop();
			ReleaseSRWLockShared(&srwLock);
			WakeAllConditionVariable(&g_cvReadyToProduce);
			Sleep(1500);
		}
	}
	return 0;
}
int main()
{
	HANDLE g_hThread[10];
	DWORD dwThreadId;
	InitializeSRWLock(&srwLock);
	InitializeConditionVariable(&g_cvReadyToConsume);
	InitializeConditionVariable(&g_cvReadyToProduce);
	int i;
	for (i = 0; i < 4; i++)
	{
		g_hThread[i] = CreateThread(NULL,
			0,
			WriteThread,
			(PVOID)(INT_PTR)i,
			0,
			&dwThreadId
		);
	}
	for (i = 0; i < 2; i++)
	{
		g_hThread[i] = CreateThread(NULL,
			0,
			ReadThread,
			(PVOID)(INT_PTR)i,
			0,
			&dwThreadId
		);
	}
	WaitForMultipleObjects(4, g_hThread, TRUE, 50000);
	for (i = 0; i < 4; i++)
		CloseHandle(g_hThread[i]);
	return 0;
}