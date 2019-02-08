#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char **s, name[10];
	int n, len, i;
	scanf("%d", &n);
	s = (char**)malloc(sizeof(char*)*n);
	for (i = 0; i < n; i++)
	{
		printf("enter name\n");
		scanf("%s", name);
		len = strlen(name);
		s[i] = (char*)malloc(sizeof(char)*len);
		strcpy(s[i], name);
	}
	for (i = 0; i < n; i++)
	{
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
	return 0;
}