#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n, r, s = 0;
	printf("enter n\n");
	scanf("%d", &n);
	while (n > 0)
	{
		r = n % 10;
		s = s + r;
		n = n / 10;
	}
	printf("Sum of digits = %d", s);
}