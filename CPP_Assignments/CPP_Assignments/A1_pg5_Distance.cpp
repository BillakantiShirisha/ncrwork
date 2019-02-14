#include<iostream>
using namespace std;
class Distance2;
class Distance1
{
	int meter, cmeter;
public:
	Distance1(int i, int j)
	{
		meter = i;
		cmeter = j;
	}
	friend void cal(Distance1, Distance2);
};
class Distance2
{
	int feet, inch;
public:
	Distance2(int k, int l)
	{
		feet = k;
		inch = l;
	}
	friend void cal(Distance1, Distance2);
};
void cal(Distance1 d1, Distance2 d2)
{
	int c;
	float t;
	cout << "Enter choice\n1:Meters\n2:Feets";
	cin >> c;
	switch (c)
	{
	case 1: t = (d1.meter) + (0.01*d1.cmeter) + (d2.feet*0.3) + (d2.inch*0.3*0.0245);
		break;
	case 2: t = (d1.meter*3.28) + (0.1f*d1.cmeter*3.28) + (d2.feet) + (0.08*d2.inch);
		break;
	default:break;
	}
	cout << t;
}
int main()
{
	Distance1 dr(4,5);
	Distance2 dt(2, 3);
	cal(dr, dt);
	return 0;
}