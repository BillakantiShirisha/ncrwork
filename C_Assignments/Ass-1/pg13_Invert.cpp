#include<stdio.h>
#include<iostream>
int rotate_right(int n, int rot)
{
	int d, s, r, i;
	d = log10(n);
	for (i = 0; i < rot; i++)
	{
		r = n % 10;
		n = n / 10;
		s = r * pow(10, d) + n;
		n = s;
	}
	return n;
}
int main()
{
	int n, b, p;
	printf("enter n,b and p\n");
	scanf("%d%d%d", &n, &b, &p);

	return 0;
}