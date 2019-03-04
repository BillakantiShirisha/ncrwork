#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<tchar.h>
#include<iostream>
using namespace std;
#define BUFFERSIZE 100
DWORD WINAPI thread_fun(LPVOID lparam)
{
	printf("In thread function\n");
	return 0;
}
int main(int argc, CHAR* argv[])
{
	//cout << "hello\n";
	cout << GetPriorityClass(GetCurrentProcess()) << "\n";
	SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);
	cout << GetPriorityClass(GetCurrentProcess()) << "\n";

	DWORD thId;
	HANDLE hThread;
	hThread = CreateThread(NULL, //SECURITY_ATTRIBUTES
		0,	//dwStacksize
		thread_fun,//Pointer to function to be executed by thread
		NULL,//Pointer to the variable to be passed to thread
		CREATE_SUSPENDED,//Creation flag controls the creation of thread
		&thId//pointer to variable that receives thread identifier
	);
	if (hThread == NULL) //failure
	{
		printf("Unable to create thread %d\n", GetLastError());
		getchar();
		return 0;
	}
	BOOL ret = SetThreadPriority(hThread, THREAD_PRIORITY_LOWEST);
	if (ret != 0)
		printf("Sucessfully the priority of thread was to %ld\n", GetThreadPriority(hThread));
	else
	{
		printf("Set priority of thread failed %d\n", GetLastError());
		return 0;
	}
	ResumeThread(hThread);
	//WaitForSingleObject(hThread, 1000);
	printf("Thread creation successfull\n");
	CloseHandle(hThread);
	return 0;
}