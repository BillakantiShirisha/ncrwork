#include<stdio.h>
#include<ctype.h>
int main()
{
	char n;
	int d = 0, a = 0, t = 0, s = 0;
	while (1)
	{
		scanf("%c", &n);
		if (n == '\n')
			break;
		else if (isalpha(n))
			a++;
		else if (isdigit(n))
			d++;
		else if (n == ' ')
			s++;
		else if (n == '\t')
			t++;
	}
	printf("alphabets=%d\ndigits=%d\nspaces=%d\n tabs=%d\n", a, d, s, t);
	return 0;
}