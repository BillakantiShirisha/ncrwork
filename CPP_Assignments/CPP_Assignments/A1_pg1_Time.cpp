#include<iostream>
using namespace std;
class Time {
	int hours, mins, secs;
public:
	Time()
	{
		hours = 0; mins = 0; secs = 0;
	}
	Time(int hr, int min, int sec)
	{
		hours = hr; mins = min; secs = sec;
	}
	void display()
	{
		cout << hours << ":" << mins << ":" << secs;
	}
	void add(Time t1, Time t2)
	{
		hours = t1.hours + t2.hours;
		mins = t1.mins + t2.mins;
		secs = t1.secs + t2.secs;
	}
};
int main()
{
	Time t1(1,4,12), t2(3, 10, 50),t3;
	t3.add(t1, t2);
	t3.display();
	t1.display();
	t2.display();
	return 0;
}
