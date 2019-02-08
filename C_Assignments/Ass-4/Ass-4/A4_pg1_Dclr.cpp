#include<stdio.h>
int main()
{
	char *s[] = { "We will teach you how to","Move a mountain","Level a building","Erase the past","Make a million" };
	int c = 0, i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; s[i][j] != '\0'; j++)
		{
			if (s[i][j] == 'e')
				c++;
		}
	}
	printf("%d", c);
	return 0;
}