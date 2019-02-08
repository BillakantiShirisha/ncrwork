#include<stdio.h>
#include<string.h>
void del(char* s,char c)
{
	char s1[10];
	int j = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != c)
		{
			s1[j] = s[i];
			j++;
		}
	}
	strcpy(s, s1);
}
int main()
{
	char s[10],c;
	scanf("%[^\n]s", s);
	//printf("%s", s);
	scanf(" %c", &c);
	//printf("%c", c);
	del(s, c);
	printf("%s", s);
	return 0;
}