#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
class Employee
{
	int empno;
	char *name;
	int salary;
public:
	Employee(int eno=0,char *s=NULL,int sal=0)
	{
		empno = eno;
		if (s != NULL)
			name = new char[(strlen(s)) + 1];
		salary = sal;
	}
	void setData(int e, char *s, int sal)
	{
		int l;
		empno = e;
		l = strlen(s);
		name = new char[l + 1];
		strcpy(name, s);
		salary = sal;
	}
	void getData()
	{
		cout << "Employee number = " << empno << endl;
		cout << "Employee name = " << name << endl;
		cout << "Salary = " << salary << endl;
	}
	Employee operator[](int i)
	{
		return  (*this)[i];
	}
	friend istream& operator>>(istream&, Employee&);
	friend ostream& operator<<(ostream&, Employee&);
};
istream& operator>>(istream &cin, Employee &e)
{
	char n[50];
	cout << "Enter employee number\n";
	cin >> e.empno;
	cout << "Enter employee name\n";
	cin >> n;
	e.name = new char[(strlen(n)) + 1];
	strcpy(e.name, n);
	cout << "Entee employee salary\n";
	cin >> e.salary;
	return cin;
}
ostream& operator<<(ostream &cout, Employee &e)
{
	cout << "Employee number = " << e.empno << endl;
	cout << "Employee name = " << e.name << endl;
	cout << "Salary = " << e.salary << endl;
	return cout;
}
int main()
{
	Employee e[5];
	int i;
	for (i = 0; i < 5; i++)
		cin >> e[i];
	for (i = 0; i < 5; i++)
		cout << e[i];
	return 0;
}