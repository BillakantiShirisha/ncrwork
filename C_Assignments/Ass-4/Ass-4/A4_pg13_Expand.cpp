#include<stdio.h>
#include<string.h>
#include<ctype.h>
void Expand(char *s1, char *s2)
{
	int i,j=0,k;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != '-')
			s2[j++] = s1[i];
		else
		{
			if (isdigit(s1[i - 1]))
			{
				for (k = s1[i - 1] - 47; k < s1[i + 1] - 48; k++)
					s2[j++] = k + 48;
			}
			else
			{
				for (k = s1[i - 1] - 96; k < s1[i + 1] - 97; k++)
					s2[j++] = k + 97;
			}
		}
	}
	s2[j] = '\0';
}
int main()
{
	char s1[50], s2[50];
	printf("enter string1\n");
	scanf("%s", s1);
	Expand(s1, s2);
	printf("%s", s2);
	return 0;
}