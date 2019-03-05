#include<stdio.h>
#include<Windows.h>
#include "mydll.h"
#include<iostream>
using namespace std;
typedef int(*add1)(int, int);
typedef int(*sub1)(int, int);
typedef int(*mul1)(int, int);
typedef int(*division1)(int, int);
typedef int(*MYPROC)(int, int);
int main()
{
	HMODULE hdl;
	int sum, sub, mul, div,a,b;
	cout << "Enter 2 numbers:\n";
	cin >> a >> b;
	MYPROC ADD, SUB, MUL, DIV;
	hdl = LoadLibraryEx(
		TEXT("D:\\C_Assignments\\ncrwork\\WindorsInternals\\Debug\\MyDll.dll"),
		NULL,
		NULL
	);
	if (hdl == NULL)
	{
		printf("LoadLibraryEx failed with error code %d\n", GetLastError());
		getchar();
		return 0;
	}
	ADD = (MYPROC)GetProcAddress(hdl, (LPCSTR)"add");
	if (ADD == NULL)
	{
		printf("Cant call proc address add");
		getchar();
		return 0;
	}
	sum = ADD(a, b);
	printf("Sum of %d and %d = %d\n",a,b, sum);

	SUB = (MYPROC)GetProcAddress(hdl, (LPCSTR)"sub");
	if (SUB == NULL)
	{
		printf("Cant call proc address add");
		getchar();
		return 0;
	}
	sub = SUB(a, b);
	printf("Difference of %d and %d = %d\n",a,b, sub);

	MUL = (MYPROC)GetProcAddress(hdl, (LPCSTR)"mul");
	if (MUL == NULL)
	{
		printf("Cant call proc address add");
		getchar();
		return 0;
	}
	mul = MUL(a, b);
	printf("Multiplication of %d and %d = %d\n",a,b, mul);

	DIV = (MYPROC)GetProcAddress(hdl, (LPCSTR)"divn");
	if (DIV == NULL)
	{
		printf("Cant call proc address add");
		getchar();
		return 0;
	}
	div = DIV(a, b);
	printf("Division of %d and %d = %d\n",a,b, div);
	FreeLibrary(hdl);
	system("pause");
	return 0;
}