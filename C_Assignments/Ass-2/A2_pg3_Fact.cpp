#include<stdio.h>
int main()
{
	long int n,fact=1;
	int i;
	printf("enter n\n");
	scanf("%ld", &n);
	for (i = 1; i <= n; i++)
		fact = fact * i;
	printf("Factorial = %ld", fact);
	return 0;
}