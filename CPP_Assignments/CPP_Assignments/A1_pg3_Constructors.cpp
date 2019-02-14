#include<iostream>
using namespace std;
class Complex
{
	float real,img;
public:
	Complex()
	{
		real = img = 0;
	}
	Complex(float r)
	{
		real = img = r;
	}
	Complex(float r, float i)
	{
		real = r;
		img = i;
	}
	friend Complex sum(Complex, Complex);
	friend Complex mul(Complex, Complex);
};
Complex sum(Complex c1, Complex c2)
{
	Complex t;
	t.real = c1.real + c2.real;
	t.img = c1.img + c2.img;
	cout << t.real << endl;
	cout << t.img << endl;
	return t;
}
Complex mul(Complex c1, Complex c2)
{
	Complex t;
	t.real = c1.real * c2.real;
	t.img = c1.img * c2.img;
	cout << t.real << endl;
	cout << t.img << endl;
	return t;
}
int main()
{
	Complex c1(), c2(5), c3(3, 8), c4, c5;
	c4 = sum(c2, c3);
	c5 = mul(c2, c3);
	return 0;
}