#include<iostream>
using namespace std;
void value(int x, int y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}
void ref(int &x, int &y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}
int main()
{
	int a , b ,n;
	cin >> a >> b >> n;
	switch (n)
	{
	case 1:value(a,b);
		break;
	case 2:ref(a, b);
		break;
	default:
		break;
	}
	cout << a << b;
	return 0;
}