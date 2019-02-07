#include<stdio.h>
int main()
{
	int i, a[10], b[10], n, m, k = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	m = n;
	for (i = 0; i < m; i++)
	{
		if (a[i] < 0)
		{
			b[k] = a[i];
			k++;

		}
		else
		{
			b[n - 1] = a[i];
			n--;
		}
	}
	for (i = 0; i < m; i++)
		printf("%d ", b[i]);
}