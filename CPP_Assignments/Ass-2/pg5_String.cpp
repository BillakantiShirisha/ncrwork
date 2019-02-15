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
		len = strlen(a);
		s = new char[len];
		strcpy(s, a);
	}
	String(char *a, int l)
	{
		len = l;
		s = new char[len];
		strcpy(s, a);
	}
	String(const String &a)
	{
		len = a.len;
		s = new char[len];
		strcpy(s, a.s);
	}
	String operator+(String s2)
	{
		String s3;
		s3.len = len + s2.len;
		if(s3.s==NULL)
		s3.s = new char[s3.len];
		strcpy(s3.s, s);
		strcat(s3.s, s2.s);
		return s3;
	}
	String operator=(String s2)
	{
		if (s == NULL)
			s = new char[strlen(s2.s)];
		strcpy(s, s2.s);
		len = s2.len;
		return *(this);
	}
	char& operator[](int i)
	{
		return s[i];
	}
	~String()
	{
		if (s != NULL)
			delete s;
	}
	friend istream& operator>>(istream&, String&);
	friend ostream& operator<<(ostream&, String);
};
istream& operator>>(istream& cin, String &s)
{
	char str[50];
	cout << "enter string" << endl;
	cin >> str;
	if (s.s == NULL)
		s.s = new char[strlen(str) + 1];
	strcpy(s.s, str);
	s.len = strlen(s.s);
	return cin;
}
ostream& operator<<(ostream& cout, String c)
{
	cout << "String = " << c.s << endl;
	return cout;
}
int main()
{
	String s1, s2, s3;
	cin >> s1 >> s2;
	s3 = s1 + s2;
	cout << "s3 = s1 + s2" << endl;
	cout << s3;
	cout << "s2[3]=s1[2]" << endl;
	s2[3] = s1[2];
	cout << "s2[3] = " << s2[3] <<endl << "s1[2] = " << s3[2] << endl;
	cout << "s1[3] = " << s1[3] << endl;
	return 0;
}