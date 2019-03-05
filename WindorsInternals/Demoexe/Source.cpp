#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include "mydll.h"
using namespace std;
int main()
{
	int left, right;
	cout << "Enter two numbers:\n";
	cin >> left >> right;
	printf("Sum and Difference of %d and %d are %d and %d\n", left, right, add(left, right), sub(left, right));
	printf("Product and Quotient of %d and %d are %d and %d\n", left, right, mul(left, right), divn(left, right));
	system("pause");
}