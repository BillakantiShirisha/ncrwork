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
	//LPCWSTR fileName = L"welcome.txt";
	hFile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("File open error : %d\n"), GetLastError());
		getchar();
		return -1;
	}
	_tprintf(_T("File openend successfully : %s\n"), argv[1]);
	DWORD nbr;
	ZeroMemory(buff, sizeof(buff));

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES sa;
	//HANDLE hProcess;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	sa.bInheritHandle = TRUE;
	ZeroMemory(&pi, sizeof(pi));
	LPWSTR lp = NULL;
	lp = new WCHAR[200];
	//cout << _countof(L"notepad");
	wcscpy_s(lp, _countof(L"\"D:\\C_Assignments\\ncrwork\\WindorsInternals\\HandleInherit2\\Source.cpp\" hFile"), L"\"D:\\C_Assignments\\ncrwork\\WindorsInternals\\HandleInherit2\\Source.cpp\" hFile");
	//wcout << lp << endl;
	if (!CreateProcess(
		NULL,
		lp,
		&sa,
		NULL,
		TRUE,
		CREATE_NEW_CONSOLE,
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

	delete lp;


	return 0;
}