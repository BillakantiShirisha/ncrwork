#include<iostream>
using namespace std;
class Student {
	char *name;
	int len;
	char g[20];
	int m1, m2, m3;
public:
	Student(char *s,char *gr,int mm1,int mm2,int mm3)
	{
		len = strlen(s);
		name = (char*)malloc(sizeof(char)*(len + 1));
		strcpy(name, s);
		strcpy(g, gr);
		m1 = mm1;
		m2 = mm2;
		m3 = mm3;
	}
	float avg()
	{
		int sum = m1 + m2 + m3;
		return sum / 3;
	}
	void grade()
	{
		float av=avg();
		if (av > 70)
			strcpy(g, "FirstClass");
		else if ((av > 60)&(av < 50))
			strcpy(g, "SecondClass");
		else if ((av > 50)&(av < 40))
			strcpy(g, "ThirdClass");
		else
			strcpy(g, "Fail");
		} 
	void display()
	{
		cout << name << " "<<m1 <<" "<< m2 << " "<<m3 <<" "<< g;
	}
};
int main()
{
	Student s("siri","empty", 70, 80, 90);
	s.grade();
	s.display();
		return 0;
}