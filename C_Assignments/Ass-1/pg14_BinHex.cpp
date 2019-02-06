#include<stdio.h>
int main()
{
	int n, num, s = 0, k = 1,r,i=0,j;
	char hexDeciNum[100];
	printf("enter n\n");
	scanf("%d", &n);
	num = n;
	while (num > 0)
	{
		r = num % 2;
		s = s + r * k;
		k = k * 10;
		num = num / 2;
	}
	printf("Binary = %d\n", s);
	num = n; s = 0; k = 1;
	while (num > 0)
	{
		r = num % 16;
		if (r < 10)
		{
			hexDeciNum[i] = r + 48;
		}
		else
		{
			hexDeciNum[i] = r + 55;
		}
		i++;
		num = num / 16;
	}
	printf("Hexadecimal = ");
	for (j = i - 1; j >= 0; j--)
		printf("%c", hexDeciNum[j]);
	//printf("HexaDecimal = %d\n", s);
}