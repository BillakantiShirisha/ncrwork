#include<stdio.h>
#include "pg1_Add.cpp"
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", add(a, b));
	return 0;
}