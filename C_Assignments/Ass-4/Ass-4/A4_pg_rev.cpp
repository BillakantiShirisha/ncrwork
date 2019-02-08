#include<stdio.h>
#include<string.h>
void reverse(char *s, int i, int j)
{
	char t;
	if (i > j)
		return;
	t = s[i];
	s[i] = s[j];
	s[j] = t;
	reverse(s, i + 1, j - 1);
}
int main()
{
	char s[20];
	scanf("%s", s);
	reverse(s, 0, strlen(s) - 1);
	printf("%s", s);
	return 0;
}