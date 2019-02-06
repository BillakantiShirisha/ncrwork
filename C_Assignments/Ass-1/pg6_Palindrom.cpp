#include<stdio.h>
#include<iostream>
int main()
{
	int n, r, s=0,num;
	printf("enter n\n");
	scanf("%d", &num);
	n = num;
	while (n > 0)
	{
		r = n % 10;
		s = s * 10 + r;
		n = n / 10;
	}
	if (s == num)
		printf("%d is Palindrom", s);
	else
		printf("%d is not a Palindrome", s);

	return 0;
}