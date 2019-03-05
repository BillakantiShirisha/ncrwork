#include<stdio.h>	
#include<iostream>
using namespace std;
#include "D:\C_Assignments\ncrwork\WindorsInternals\StaticLink\mydll.h"
int main()
{
	double a, b;
	cout << "Enter two numbers:\n";
	cin >> a >> b;
	printf("%lf + %lf = %lf\n", a, b, MyMathFunctions::add(a, b));
	printf("%lf + %lf = %lf\n", a, b, MyMathFunctions::sub(a, b));
	printf("%lf + %lf = %lf\n", a, b, MyMathFunctions::mul(a, b));
	printf("%lf + %lf = %lf\n", a, b, MyMathFunctions::divn(a, b));
	system("pause");
	return 0;
}