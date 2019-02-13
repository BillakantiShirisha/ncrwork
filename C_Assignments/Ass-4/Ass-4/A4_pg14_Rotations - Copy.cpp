#include<stdio.h>
#include<string.h>
void Rotations(char *s)
{
	int i, l , j;
	char t;
	l = strlen(s);
	for (i = 0; i < l; i++)
	{
		t = s[l - 1];
		for (j = l - 1; j >= 0; j--)
			s[j] = s[j - 1];
		s[0] = t;
		printf("%s	", s);
	}
}
int main()
{
	char s[50];
	printf("enter string\n");
	scanf("%s", s);
	Rotations(s);
	return 0;
}