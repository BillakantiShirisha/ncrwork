//Example program for CommandLineArgvW API
#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	LPWSTR *szArglist;
	int nArgs;
	szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
	if (NULL == szArglist)
	{
		cout << "CommandLineToArgvW failed";
		return 0;
	}
	else
	{
		for (int i = 0; i < nArgs; i++)
			wcout << szArglist[i]<<endl;
	}
	getchar();
	return 0;
}