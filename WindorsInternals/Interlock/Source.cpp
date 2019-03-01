#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>
long g_x=0;
DWORD WINAPI thread_fun(LPVOID lparam)
{
	InterlockedExchangeAdd(&g_x, 1);
	return 0;
}
DWORD WINAPI thread_func1(LPVOID lparam)
{
	InterlockedExchangeAdd(&g_x, 1);
	return 0;
}
int main()
{
	DWORD thId1, thId2;
	HANDLE hTh1, hTh2;
	HANDLE arr_hand[2];
	while (1)
	{
		g_x = 0;
		hTh1 = CreateThread(NULL, 0, thread_fun, NULL, 0, &thId1);
		if (hTh1 == NULL)
		{
			printf("Unable to create the thread\n");
			getchar();
			return 1;
		}
		hTh2 = CreateThread(NULL, 0, thread_fun, NULL, 0, &thId2);
		if (hTh2 == NULL)
		{
			printf("Unable to create the thread\n");
			getchar();
			return 1;
		}
	}
}