#include<stdio.h>
#include<string.h>
void deletes2(char *s1, char *s2)
{
	int i, j ,k,f;
	for (i = 0, j = 0; s1[i] != '\0'; i++)
	{
		f = 0;
		for (k = 0; s2[k] != '\0'; k++)
		{
			if (s1[i] == s2[k])
			{
				f++;
				break;
			}
		}
		if (f == 0)
		{
			s1[j] = s1[i];
			j++;
		}
	}
	s1[j] = '\0';
}
int main()
{
	char s1[50], s2[50];
	printf("enter string1\n");
	scanf("%[^\n]s", s1);
	printf("enter string2\n");
	scanf(" %[^\n]s", s2);
	deletes2(s1, s2);
	printf("%s", s1);
	return 0;
}