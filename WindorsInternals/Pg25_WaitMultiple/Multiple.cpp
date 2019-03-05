#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>
DWORD WINAPI thread_fun1(LPVOID lparam)
{
		Sleep(4000);
		return 1;
}
DWORD WINAPI thread_fun(LPVOID lparam)
{
	printf("HELLO");
		Sleep(2000);
		return 1;
}
int main()
{
	DWORD thId1, thId2;
	HANDLE hTh1, hTh2;
	HANDLE arr_hand[2];
	hTh1 = CreateThread(NULL, 0, thread_fun, NULL, 0, &thId1);
	if (hTh1 == NULL)
	{
		printf("Unable to create the thread\n");
		getchar();
		return 1;
	}
	hTh2 = CreateThread(NULL, 0, thread_fun1, NULL, 0, &thId2);
	if (hTh2 == NULL)
	{
		printf("Unable to create the thread\n");
		getchar();
		return 1;
	}
	arr_hand[0] = hTh1;
	arr_hand[1] = hTh2;
	DWORD dw = WaitForMultipleObjects(2,arr_hand,TRUE,5000);
	switch (dw)
	{
	case WAIT_TIMEOUT:
		printf("Timeout expired.\n");
		break;
	case WAIT_FAILED:
		printf("Wait failed.\n");
		break;
	case WAIT_OBJECT_0+0:
		printf("Thread 1 is terminated.\n");
		break;
	case WAIT_OBJECT_0+1:
		printf("Thread 2 is terminated.\n");
		break;
	}
	CloseHandle(hTh1);
	CloseHandle(hTh2);
	printf("Waiting for user input before exiting the process\n");
	getchar();
	return 0;
}