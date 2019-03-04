#include <iostream>
using namespace std;
class Base
{
	int x;
public:
	virtual void display()
	{
		cout << "Base class";
	}
	Base()
	{
		x = 2;
		y = 3;
		z = 4;
	}
	int y;
protected:
	int z;
};

class priD : private Base
{
public:
	void display()
	{
		//y & z become private
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
	}
};
class PubD : public Base
{
public:
	void display()
	{
		//y & z become public
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
	}
};
class proD : protected Base
{
public:
	void display()
	{
		//y & z become protected
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
	}
};
int main()
{
	Base obj;
	Base *ob;
	PubD pub;//public members become public and can be accessed outside the class
	cout << "Public varaiable in Base class is:" << pub.y << endl;
	priD pri;//public members become private and cannot be accesses outside the class
	proD pro;//public members become protected and cannot be accesses outside the class
	ob = &pub;
	ob->display();//(only the public class display function can be accessed)
	getchar();
	return 0;
}