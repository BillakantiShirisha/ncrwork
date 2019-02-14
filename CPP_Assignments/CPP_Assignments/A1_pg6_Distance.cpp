#include<iostream>
using namespace std;
class Size
{
	int i;
public:
	Size(int x)
	{
		cout << "Call by Value\n";
	}
	Size(Size &c)
	{
		cout << "Call by Reference\n";
	}
};
int main()
{
	Size c1(2), c2(c1);
	cout << sizeof(c1)<<endl<<sizeof(c2);
	return 0;
}