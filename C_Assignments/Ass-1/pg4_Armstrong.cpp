#include<stdio.h>
#include<math.h>
int main()
{
	int n, r, s = 0, d,num;
	printf("enter n\n");
	scanf("%d", &num);
	d = log10(num) + 1;
	n = num;
	while (n > 0)
	{
		r = n % 10;
		s = s + pow(r, d);
		n = n / 10;
	}
	if (s == num)
		printf("%d is Armstrong", num);
	else
		printf("%d is not Armstrong", num);
	return 0;
}