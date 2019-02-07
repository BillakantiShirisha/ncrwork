#include<stdio.h>
int main()
{
	int a[] = { 10,20,30,40,50,60,70,80 };
	printf("x = %d\n", a);
	printf("(x+2) = %d\n", a + 2);
	printf("*x = %d\n", *a);
	printf("(*x + 2) = %d\n", (*a + 2));
	printf("*(x+2) = %d\n", *(a + 2));

}