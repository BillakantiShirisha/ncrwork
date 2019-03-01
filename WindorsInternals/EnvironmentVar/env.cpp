//program for retrieving Environment variables
#include<Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;
void DumpEnvStrings(PTSTR pEnvBlock[])
{
	int count = 0;
	PTSTR *pElement = (PTSTR*)pEnvBlock;
	PTSTR pCurrent = NULL;
	while (pElement != NULL)
	{
		pCurrent = (PTSTR)(*pElement);
		if (pCurrent == NULL)
			pElement = NULL;
		else
		{
			//printing the count and variable name
			_tprintf(TEXT("[%u] %s\n"),++count,pCurrent);
			pElement++;
		}
	}
}
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvStrings(env);
	TCHAR envVarString[] = TEXT("%systemRoot%");
//	TCHAR envVarString[] = TEXT("%windir%");
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envVarString, buffer, MAX_PATH);
	//checking the returned value
	if (!ret)
	{
		printf("%d", GetLastError());
		getchar();
		return 0;
	}
	else
		wcout <<"Buffer is:"<< buffer;
	getchar();
	return 0;
}