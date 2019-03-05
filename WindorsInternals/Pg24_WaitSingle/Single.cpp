#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>
DWORD WINAPI thread_fun(LPVOID lparam)
{
	for (int i = 0; i < 5; i++)
	{
		printf("i=%d\n", i);
		//Sleep(1000);
	}
	return 0;
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
		DWORD dw = WaitForSingleObject(hTh1, 1000);
		switch (dw)
		{
		case WAIT_OBJECT_0:
			printf("Thread is terminated.\n");
			break;
		case WAIT_TIMEOUT:
			printf("Timeout expired.\n");
			break;
		case WAIT_FAILED:
			printf("Wait failed.\n");
			break;
		}
	CloseHandle(hTh1);
	printf("Waiting for user input before exiting the process\n");
	getchar();
	return 0;
}