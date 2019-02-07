#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int replace(char *cat)
{
	int c = 0;
	for (int i = 0; cat[i] != '\0'; i++)
	{
		if (cat[i] == ' ')
		{
			cat[i] = '-';
			c++;
		}
	}
	return c;
}
int main()
{
	int n;
	char *p = (char *)malloc(12 * sizeof(char));
	strcpy(p, "The cat sat");
	n = replace(p);
	printf("%d\n", n);
	printf("%s", p);
	return 0;
}