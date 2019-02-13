#include<stdio.h>
#include<string.h>
int any(char s1[], char s2[])
{
	int i,j,f=0,k;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == s2[0])
		{
			f = 0;
			for (j = 1, k = i + 1; s2[j] != '\0'; j++, k++)
			{
				if (s1[k] != s2[j])
				{
					f++;
					break;
				}
			}
			if (f == 0)
				return i;
		}
	}
	return -1;
}
int main()
{
	char s1[50], s2[50];
	printf("enter string1\n");
	scanf("%[^\n]s", s1);
	
	printf("enter string2\n");
	scanf(" %[^\n]s", s2);
	
	printf("%d", any(s1, s2));
	//printf("%s\n", s1);
	//printf("%s", s2);
	return 0;
}