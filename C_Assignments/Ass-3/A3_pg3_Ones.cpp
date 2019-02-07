#include<stdio.h>
int main()
{
	long int n;
	int r,i=0, c = 0;
	scanf("%ld", &n);
	while (n > 0)
	{
		r = n % 10;
		if (r == 1)
			c++;
		n = n / 10;
	}
	printf("%d", c);
	return 0;
}