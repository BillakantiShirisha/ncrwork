#include<stdio.h>
#include<iostream>
using namespace std;
class Complex
{
	float real;
	float img;
public:
	Complex()
	{
		real = img = 0;
	}
	Complex(float f)
	{
		real = img = f;
	}
	Complex(float r, float i)
	{
		real = r;
		img = i;
	}
	Complex operator+(Complex b)
	{
		Complex temp;
		temp.real = real + b.real;
		temp.img = img + b.img;
		return temp;
	}
	Complex operator-(Complex b)
	{
		Complex temp;
		temp.real = real - b.real;
		temp.img = img - b.img;
		return temp;
	}
	Complex operator-()
	{
		Complex c;
		c.real = -real;
		c.img = -img;
		return c;
	}
	Complex operator++()
	{
		real++;
		img++;
		return *(this);
	}
	Complex operator++(int i)
	{
		Complex c;
		c.real = real++;
		c.img = img++;
		return c;
	}
	Complex operator=(Complex a)
	{
		real = a.real;
		img = a.img;
		return *(this);
	}
	Complex operator,(Complex a)
	{
		return a;
	}
	Complex* operator->()
	{
		return this;
	}
	void add()
	{
		cout << "In add" << endl;
	}
	friend istream& operator>>(istream&, Complex&);
	friend ostream& operator<<(ostream&, Complex c);
};
istream& operator>>(istream &cin, Complex &c)
{
	printf("enter real and complex\n");
	cin >> c.real >> c.img;
	return cin;
}
ostream& operator<<(ostream &cout, Complex c)
{
	cout << c.real << "+" << c.img << "i" << endl;
	return cout;
}
int main()
{
	Complex c1, c2,c3;
	cin >> c1 >> c2;
	c3 = c1 + c2;
	cout << "Sum " << endl;
	cout << c3;
	cout << "Difference" << endl;
	c3 = c1 - c2;
	cout << c3;
	c3 = -c1;
	cout << "-C1" << endl;
	cout << c3;
	/*c3 = ++c1;
	cout << "c3 = ++c1" << endl;
	cout << "c3 = "<<c3; cout << "c1 = " << c1;
	c3 = c1++;
	cout << "c3 = c1++" << endl;
	cout << "c3 = " << c3; cout << "c1 = " << c1;*/
	c3 = c1, c2;
	cout << "c3 = c1,c2"<<endl;
	cout << c3;
	cout << "c3 = (c1,c2)"<<endl;
	c3 = (c1, c2);
	cout << c3;
	cout << "c1->add" << endl;
	c1->add();
	return 0;
}