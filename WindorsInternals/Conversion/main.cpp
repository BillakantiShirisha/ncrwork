//Example program for converting multibyte to widechar and vice versa
#include<Windows.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	CHAR c[] = "hello";
	WCHAR w[] = L"cool";
	int un1, un2, r;
	// testing unicode or not
	un1 = IsTextUnicode(c, strlen(c), NULL);
	if (un1 == 0)
		cout << "c is not an unicode " << endl;
	else
		cout << "c is an unicode " << endl;
	un2 = IsTextUnicode(w, wcslen(w), NULL);
	if (un2 == 0)
		cout << "w is not an unicode " << endl;
	else
		cout << "w is an unicode " << endl;
	//multicode(ANSI) to widechar(UNICODE)
	r = MultiByteToWideChar(CP_UTF8, 0, c, -1, NULL, 0);
	if (r == 0)
		cout << "error occured" << GetLastError();
	WCHAR *Warray = new WCHAR[r];
	int req = MultiByteToWideChar(CP_UTF8, 0, c, -1, Warray, r);
	un1 = IsTextUnicode(c, strlen(c), NULL);
	if (req == 0)
		cout << "c is not converted to widechar " << endl;
	else
		cout << "c is converted to widechar " << endl;
	cout << Warray << endl;
	printf("%S\n", Warray);
	//Widechar(UNICODE) to Multibyte(ANSI)
	r = WideCharToMultiByte(CP_UTF8, 0, w, -1, NULL, 0, NULL, NULL);
	if (r == 0)
		cout << "error occured" << GetLastError();
	CHAR *Carray = new CHAR[r];
	req = WideCharToMultiByte(CP_UTF8, 0, w, -1, Carray, r, NULL, NULL);
	un1 = IsTextUnicode(c, strlen(c), NULL);
	if (req == 0)
		cout << "w is not converted to Multibyte " << endl;
	else
		cout << "w is conerted to Multibyte " << endl;
	printf("%s\n", Carray);
	getchar();
	return 0;
}