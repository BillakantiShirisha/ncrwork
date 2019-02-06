#include<stdio.h>
#include<math.h>
int main()
{
	double p = 500000, si, pi,amount,t=5,r=10;
	amount = p + (p * t * r / 100);
	printf("Simple interest for 5 years Amount = %f", amount);
	amount = p * pow((1 + r / 100), 5);
	printf("Compound interest when compounded anually = %f\n", amount);
	amount = p * pow((1 + r / 200), 10);
	printf("Compound interest when compounded half anually = %f\n", amount);
	amount = p * pow((1 + r / 400), 20);
	printf("Compound interest when compounded quarterly = %f\n", amount);
	amount = p * pow((1 + r / 1200), 60);
	printf("Compound interest when compounded monthly = %f\n", amount);
	amount = p * pow((1 + r / 36500), 1825);
	printf("Compound interest when compounded daily = %f\n", amount);
	return 0;
}