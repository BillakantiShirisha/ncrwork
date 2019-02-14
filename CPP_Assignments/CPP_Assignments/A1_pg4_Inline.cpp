#include<iostream>
using namespace std;
inline int add(int a, int b)
{
	return a+b;
}
inline int mul(int a, int b)
{
	return a*b;
}
inline int sub(int a, int b)
{
	return a-b;
}
inline int divs(int a, int b)
{
	return a/b;
}
inline int mod(int a, int b)
{
	return a%b;
}
int main()
{
	int x, y;
	cin >> x >> y;
	cout << add(x, y)<<endl;
	cout << sub(x, y)<<endl;
	cout << mul(x, y)<<endl;
	cout << divs(x, y)<<endl;
	cout << mod(x, y);
	return 0;
}