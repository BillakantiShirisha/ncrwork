#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,cnt=0,len,j,k=0,l=0;
	char s1[50], *ptr , c,**res,s2[50];
	printf("enter string\n");
	scanf("%[^\n]s",s1);
	printf("enter delimiter\n");
	scanf(" %c", &c);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == c)
			cnt++;
	}
	//printf("%d", cnt);
	res = (char**)malloc(sizeof(char*)*(cnt + 1));
	for (i = 0; i < cnt + 1 ; i++)
	{
		//strcpy(s2, s1);
		len = strlen(s1);
		res[i] = (char*)malloc(sizeof(char)*(len + 1));
		for (j = k,l=0; s1[j]!='\0' ; j++,l++)
		{
			k++;
			if (s1[j] != c)
				res[i][l] = s1[j];
			if (s1[j] == c)
				break;
			
		}
		res[i][l] = '\0';
	}
	for (i = 0; i < cnt + 1; i++)
	{
		printf("%s\n", res[i]);
	}
	return 0;
}