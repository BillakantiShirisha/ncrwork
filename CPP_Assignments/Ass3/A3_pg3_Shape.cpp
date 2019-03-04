#include<iostream> 
using namespace std;
class Shape
{
public:
	virtual void displayArea()
	{
		cout << "Shape class displayArea" << endl;
	}
};
class Triangle :public Shape
{
public:
	void displayArea()
	{
		cout << "Area of Triangle is 1/2(b*h)" << endl;
	}
};
class Square :public Shape
{
public:
	void displayArea()
	{
		cout << "Area of Square s*s" << endl;
	}
};
class Rectangle :public Shape
{
public:
	void displayArea()
	{
		cout << "Area of Rectangle is l*b" << endl;
	}
};
int main()
{
	Shape *s, sh;
	sh.displayArea();//Shape class area
	Triangle tri;
	s = &tri;
	s->displayArea();//Triangle class area
	Square sqr;
	s = &sqr;
	s->displayArea();//Square class area
	Rectangle rec;
	s = &rec;
	s->displayArea();//Rectangle class area
	getchar();
	return 0;
}