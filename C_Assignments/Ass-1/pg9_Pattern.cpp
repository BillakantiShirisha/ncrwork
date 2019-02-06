#include<stdio.h>
#include<iostream>
int main()
{
	int i, j, n;
	printf("enter n\n");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = n - i; j > 0; j--)
			printf(" ");
		for (j = i; j >= 1; j--)
			printf("%d", j);
		for (j = 2; j <= i; j++)
			printf("%d", j);
		printf("\n");
	}
	return 0;
}