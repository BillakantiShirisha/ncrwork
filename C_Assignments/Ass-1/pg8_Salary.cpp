#include<stdio.h>
int main()
{
	float basic, hra, da, gross;
	printf("enter basic\n");
	scanf("%f", &basic);
	if (basic <= 4000)
	{
		hra = basic * 10 / 100;
		da = basic * 50 / 100;
	}
	else if (basic >= 4001 && basic <= 8000)
	{
		hra = basic * 20 / 100;
		da = basic * 60 / 100;
	}
	else if (basic >= 8001 && basic <= 12000)
	{
		hra = basic * 27 / 100;
		da = basic * 70 / 100;
	}
	else
	{
		hra = basic * 30 / 100;
		da = basic * 80 / 100;
	}
	gross = basic + hra + da;
	printf("%f", gross);
	return 0;
}