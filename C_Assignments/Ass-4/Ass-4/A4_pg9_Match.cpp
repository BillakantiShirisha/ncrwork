#include<stdio.h>
int any(char *s1, char *s2)
{
	int i, j,f=0,k;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if ((s1[i] == s2[i])&&(s1[i]!=' '))
		{
			k = i;
			for (j = i; ((s1[j] != '\0') && (s1[j] != ' ')); j++)
			{
				if (s1[j] != s2[j])
				{
					f = 1;
					break;
				}
			}
			if (f == 0)
				return i;
		}
		i = j;
		f = 0;
	}
	return 0;
}
int main() {
	char s1[10], s2[10];
	int p;
	scanf("%[^\n]s", s1);
	scanf(" %[^\n]s", s2);
	p = any(s1, s2);
	printf("%d", p);
	return 0;
}