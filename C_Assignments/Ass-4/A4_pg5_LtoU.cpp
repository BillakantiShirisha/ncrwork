#include<stdio.h>
#include<ctype.h>
int main()
{
	char s[10];
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (isupper(s[i]))
			s[i]=tolower(s[i]);
		else
			s[i]=toupper(s[i]);
	}
	printf("%s", s);
	return 0;
}