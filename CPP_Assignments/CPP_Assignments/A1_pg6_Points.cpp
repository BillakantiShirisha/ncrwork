#include<iostream>
using namespace std;
class Point {
	int i, j;
public:
	Point(int t, int u)
	{
		i = t;
		j = u;
	}
	friend void calc(Point, Point);
};
void calc(Point p1, Point p2)
{
	int p;
	p = sqrt(((p2.i - p1.i)*(p2.i - p1.i)) + ((p2.j - p1.j)*(p2.j - p1.j)));
		cout << p;
}
int main()
{
	Point pt(2, 3), pr(4, 8);
	calc(pt, pr);
	return 0;
}