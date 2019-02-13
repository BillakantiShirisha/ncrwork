#include<stdio.h>
void strrev(char *s)
{
	char *p, *q,t;
	int l;
	for (l = 0; s[l] != '\0'; l++);
	for (p = s, q = s + l - 1; p < q; p++, q--)
	{
		t = *p;
		*p = *q;
		*q = t;
	}
}
void strcpy(char *s2, char *s1)
{
	while ((*s2++ = *s1++) != '\0');
}
void strcat(char *s1, char *s2)
{
	while ((*s1++) != '\0'); *s1--;
	while ((*s1++ = *s2++) != '\0');
}
int strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++)
	{
		if ((*s1) == '\0')
			return 0;
	}
	*s1--; *s2--; 
	if ((*s1 - *s2) > 0)
		return 1;
	else
		return -1;
}
int main()
{
	char s[50],s2[50];
	int c,t;
	printf("enter string\n");
	scanf("%s", s);
	printf("enter choice 1.strrev 2.strcpy 3.strcat 4.strcmp\n");
	scanf("%d", &c);
	switch (c)
	{
	case 1:strrev(s); printf("%s ", s);
		break;
	case 2:strcpy(s2, s); printf("%s ", s2);
		break;
	case 3:printf("enter string2\n"); scanf("%s", s2);
		strcat(s, s2); printf("%s", s);
		break;
	case 4:printf("enter string2\n"); scanf("%s", s2);
		t = strcmp(s, s2) ;
		if (t == 0)
			printf("equal");
		else if (t == 1)
			printf("%s is greater than %s", s, s2);
		else if(t==-1)
			printf("%s is less than %s", s, s2);
		break;
	}
	return 0;
}