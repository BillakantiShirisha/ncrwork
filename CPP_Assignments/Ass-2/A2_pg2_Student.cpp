#include<iostream>
using namespace std;
class Student {
	char *name;
	int rno, m[3], tot, g;
public:
	friend ostream& operator<<(ostream &cout, Student c);
	friend istream& operator>>(istream &cin, Student &c);
	friend void generate(Student[], int n);
};
istream& operator>>(istream &cin, Student &c)
{
	char sname[50];
	cout << "enter name\n";
	cin >> sname;
	c.name = new char[strlen(sname) + 1];
	strcpy(c.name, sname);
	cout << "enter roll number\n";
	cin >> c.rno;
	cout << "enter each subject marks\n";
	for (int i = 0; i < 3; i++)
		cin >> c.m[i];
	return (cin);
}
void generate(Student s[], int n)
{
	int su,a;
	for (int i = 0; i < n; i++)
	{
		su = 0;
		for (int j = 0; j < 3; j++)
		{
			su = su + s[i].m[j];
		}
		s[i].tot = su;
		a = su / 3;
		if (a > 90)
			s[i].g = 10;
		else if ((a < 80) && (a > 70))
			s[i].g = 9;
		else if ((a < 70) && (a > 60))
			s[i].g = 8;
		else if ((a < 60) && (a > 50))
			s[i].g = 7;
		else if ((a < 50) && (a > 40))
			s[i].g = 6;
		else
			s[i].g = 5;
	}
}
ostream& operator<< (ostream &cout, Student c)
{
	cout << c.name << endl;
	cout << c.rno << endl;
	for(int i=0;i<3;i++)
	cout << c.m[i] << endl;
	cout << c.tot << endl;
	cout << c.g << endl;
	return cout;
}
int main()
{
	Student s[4];
	int i,n;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> s[i];
	generate(s, n);
	for (i = 0; i < n; i++)
		cout << s[i];
	return 0;
}