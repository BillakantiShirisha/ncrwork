#include<iostream>
using namespace std;
class Polar
{
	int angle, radius;
public:
	static int count;
	Polar(int i, int j)
	{
		angle = i;
		radius = j;
		count++;
	}
	~Polar()
	{
		count--;
	}
};
int Polar::count;
int main()
{
	Polar p1(20, 90),p2(15,80);
	cout << Polar::count;
	return 0;
}