#include<Windows.h>
#include<stdio.h>
#include<strsafe.h>
#include<tchar.h>
#include<iostream>
using namespace std;
#define BUFFERSIZE 100
int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hFile;
	TCHAR buff[BUFFERSIZE];
	//_tprintf(_T("%S"), argv[1]);
	//return 0;
	//SECURITY_ATTRIBUTES *sAttr;
	SECURITY_ATTRIBUTES sattr;
	sattr.bInheritHandle = TRUE;
	sattr.lpSecurityDescriptor = 0;
	sattr.nLength = sizeof(SECURITY_DESCRIPTOR);
	//sAttr = &sattr;
	LPCSTR fileName = "Welcome.txt";
	hFile = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, &sattr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File open error : %d\n"), GetLastError());
		getchar();
		return -1;
	}
	_tprintf(_T("File openend successfully : %s\n"), fileName);
	//DuplicateHandle(GetCurrentProcess(),hFile,)
	DWORD nbr;
	//ZeroMemory(buff, si);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES sa;
	SECURITY_ATTRIBUTES *sA = &sa;;
	//HANDLE hProcess;
	CHAR tszFileHandleString[16];
	//CHAR a = (CHAR)hFile;
	//printf("Handle value = %\n", hFile);
	sprintf(tszFileHandleString, "%d", hFile);
	printf("Handle value = %s\n", tszFileHandleString);
	printf("Handle value = %d\n", hFile);
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&sa, sizeof(sa));
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = 0;
	sa.nLength = sizeof(SECURITY_DESCRIPTOR);
	ZeroMemory(&pi, sizeof(pi));
	LPSTR lp = NULL;
	lp = new CHAR[200];
	//cout << _countof(L"notepad");
	//strcpy(lp, "\"HI.exe\"");
	//strcat(lp, " ");
	strcpy(lp, tszFileHandleString);
	//wcout << lp << endl;
	cout << lp << "\n";
	//wcscpy_s(lp, _countof(L"notepad"), L"notepad");
	if (!CreateProcess(
		_T("Source1.exe"),
		lp,
		sA,
		NULL,
		TRUE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	))
	{
		printf("Create process error %d\n", GetLastError());
		getchar();
		return 0;
	}
	printf("Handle of process %ld\n", pi.hProcess);
	printf(" Process id process %ld\n", pi.dwProcessId);
	printf("Handle of thread %ld\n", pi.hThread);
	printf(" Process id thread %ld\n", pi.dwThreadId);
	cout << "\n";
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	printf("Child process %d finished.\n", pi.dwProcessId);
	delete lp;
	return 0;
}