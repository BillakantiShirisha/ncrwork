#include<stdio.h>
int main()
{
	int n, c = 0, s = 0, min = 100000, max = 0;
	while (1)
	{
		scanf("%d", &n);
		if (n <= 0)
			break;
		c++;
		s = s + n;
		if (n < min)
			min = n;
		else if (n > max)
			max = n;
	}
	printf("Count =%d\nMinimum = %d\nMaximum = %d\nAverage = %d", c, min, max, s / c);
	return 0;
}