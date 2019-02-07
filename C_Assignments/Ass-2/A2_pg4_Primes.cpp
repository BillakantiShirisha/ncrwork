#include<stdio.h>
int main()
{
	int st, end,i,j,c=0;
	printf("enter start and end\n");
	scanf("%d%d", &st, &end);
	for (i = st; i <= end; i++)
	{
		c = 0;
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				c++;
				break;
			}
		}
		if (c == 0)
			printf("%d ", i);
	}
	return 0;
}