#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class person
{
public:
	string name;
	int age;
	person()
	{
		name = "Sirisha";
		age = 21;
	}
	void displayP()
	{
		printf("Name is %s and age is %d\n", name.c_str(), age);
	}
};
//Inheriting person class
class physique : virtual public person
{
public:
	int height;
	int weight;
	physique()
	{
		height = 15;
		weight = 50;
	}
	void displayPh()
	{
		printf("Height is %d and weight is %d\n", height, weight);
	}
};
//Inheriting person class
class family : virtual public person
{
public:
	int numChildren;
	string religion;
	family()
	{
		numChildren = 0;
		religion = "Hindu";
	}
	void displayF()
	{
		printf("Number of children are %d and religion is %s\n", numChildren, religion.c_str());
	}
};
//Inheriting physique and family class
class employee : public physique, public family
{
public:
	int eno;
	float salary;
	employee()
	{
		eno = 9;
		salary = 60000.0f;
	}
	void displaye()
	{
		displayP();
		displayPh();
		displayF();
		printf("Employee number is %d and salary is %f\n", eno, salary);
	}
};
int main()
{
	employee obj1;
	// calling all display functions
	obj1.displaye();
	getchar();
	return 0;
}