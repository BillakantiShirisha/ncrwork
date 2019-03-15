#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//Function to expand the string
char* ExpandString(char *string1, char *string2)
{
	int i, j = 0, k;
	for (i = 0; string1[i] != '\0'; i++)
	{
		//Checking weather the character is -
		if (string1[i] != '-')
		{
			string2[j++] = string1[i];
		}
		//Character is alphabet or digit
		else
		{
			for (k = string1[i - 1] + 1; k < string1[i + 1]; k++)
				string2[j++] = k;
		}
	}
	string2[j] = '\0';
	return string2;
}
int main()
{
	char *string1, *string2;
	int size1, size2;
	printf("Enter length of string\n");
	scanf("%d", &size1);
	string1 = (char*)malloc(sizeof(char)*size1);
	printf("Enter string1\n");
	scanf("%s", string1);
	printf("Enter length of output string\n");
	scanf("%d", &size2);
	string2 = (char*)malloc(sizeof(char)*size2);
	printf("Expanded string is %s", ExpandString(string1, string2));
	free(string1);
	free(string2);
	getchar();
	return 0;
}