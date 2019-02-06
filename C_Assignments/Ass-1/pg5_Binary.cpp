#include<stdio.h>
#include<iostream>
int main()
{
	int num, bin, r, s = 0, k = 1, n, b = 100000, c = 0, i;
	printf("enter a number from 1 to 31");
	scanf("%d", &num);
	n = num;
	while (num > 0)
	{
		r = num % 2;
		s = s + r * k;
		k = k * 10;
		num = num / 2;
		c++;
	}
	for (i = c; i < 5; i++)
		k = k * 10;
	s = s + k;
	printf("%d", s);
	return 0;
}