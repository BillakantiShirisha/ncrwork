#include<stdio.h>
#include<math.h>
int main()
{
	int bin, s=0,d,r,k=1,num,n;
	printf("enter binary number\n");
	scanf("%d", &bin);
	while (bin > 0)
	{
		r = bin % 10;
		s = s + r * k;
		k = k * 2;
		bin = bin / 10;
	}
	printf("%d\n", s);
	printf("enter decimal number\n");
	scanf("%d", &n);
	num = n; s = 0; k = 1;
	while (num > 0)
	{
		r = num % 2;
		s = s + r * k;
		k = k * 10;
		num = num / 2;
	}
	printf("Binary = %d\n", s);
	return 0;
}