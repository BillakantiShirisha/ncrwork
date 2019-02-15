#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class String
{
	char *s;
	int len;
public:
	String()
	{
		s = NULL;
		len = 0;
	}
	String(char *a)
	{
		//cout << "Constructor" << endl;
		len = strlen(a);
		s = new char[len+1];
		strcpy(s, a);
		//cout << s;
	}
	String(char *a, int l)
	{
		len = l;
		s = new char[len+1];
		strcpy(s, a);
	}
	/*String(const String &a)
	{
		len = a.len;
		s = new char[len+1];
		strcpy(s, a.s);
	}*/
	void printString()
	{
		if (s != NULL)
			cout << s << endl;
	}
	~String()
	{
		if (s != NULL)
			free(s);
	}
};
int main()
{
	String s1("vishnu"), s2(s1),s3;
	s1.printString(); s2.printString();
	return 0;
}