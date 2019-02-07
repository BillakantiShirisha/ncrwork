#include<stdio.h>
int main()
{
	int a[100],i,n,s=0,sum,f=0,j;
	printf("enter number\n");
	scanf("%d", &n);
	printf("enter array elements\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("enter sum\n");
	scanf("%d", &sum);
	for (i = 0; i < n; i++)
	{
		s= a[i]; 
		for (j = i + 1; j < n; j++)
		{
			s = s + a[j];
			if (s > sum)
				break;
			else if (sum == s)
			{
				printf("%d %d", i, j);
				f = 1;
				break;
			}
		}
		if (f == 1)
			break;
	}
	if (f == 0)
		printf("No SubArray found");
	return 0;
}