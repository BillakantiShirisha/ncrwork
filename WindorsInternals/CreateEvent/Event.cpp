#include<Windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	HANDLE Event = CreateEvent(NULL, FALSE, FALSE, TEXT("NamedEvent"));
	if (Event == NULL)
		printf("CreateEvent Failed");
	else
		printf("Event Created");
	//CloseHandle(Event);
	getchar();
	return 0;
}