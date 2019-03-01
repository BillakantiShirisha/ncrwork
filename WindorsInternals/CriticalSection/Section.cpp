//Critical Section program
#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>
const int count = 50;
int g_nsum = 0;
CRITICAL_SECTION g_cs;
DWORD WINAPI FirstThread(LPVOID lparam)
{
	EnterCriticalSection(&g_cs);
	//g_nsum = 0;
	for (int i = 1; i <= count; i++)
		g_nsum += i;
	LeaveCriticalSection(&g_cs);
	return g_nsum;
}
DWORD WINAPI SecondThread(LPVOID lparam)
{
	EnterCriticalSection(&g_cs);
	//g_nsum = 0;
	for (int i = 1; i <= count; i++)
		g_nsum += i;
	LeaveCriticalSection(&g_cs);
	return g_nsum;
}
int main()
{
	DWORD thId1, thId2;
	HANDLE hTh1, hTh2;
	HANDLE arr_hand[2];
	InitializeCriticalSection(&g_cs);
	int c = 0;
	while (1)
	{
		c++;
		g_nsum = 0;
		hTh1 = CreateThread(NULL, 0, FirstThread, NULL, 0, &thId1);
		if (hTh1 == NULL)
		{
			printf("Unable to create the thread\n");
			getchar();
			return 1;
		}
		hTh2 = CreateThread(NULL, 0, SecondThread, NULL, 0, &thId2);
		if (hTh2 == NULL)
		{
			printf("Unable to create the thread\n");
			getchar();
			return 1;
		}
		arr_hand[0] = hTh1;
		arr_hand[1] = hTh2;
		WaitForMultipleObjects(2, arr_hand, TRUE, INFINITE);
		printf("%d\n", g_nsum);
		if (c == 10)
			break;
	}
	printf("Waiting for user input before exiting the process\n");
	CloseHandle(hTh1);
	CloseHandle(hTh2);
	getchar();
	return 0;
}