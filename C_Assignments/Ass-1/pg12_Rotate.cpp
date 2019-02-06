#include<stdio.h>
#include<iostream>
using namespace std;
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
	int n, rot;
	printf("enter n\n");
	scanf("%d", &n);
	scanf("%d", &rot);
	n = rotate_right(n, rot);
	printf("%d", n);
	return 0;
}