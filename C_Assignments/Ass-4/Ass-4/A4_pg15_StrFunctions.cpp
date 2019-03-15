#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//Function to reverse the string
char* strrev(char *string1)
{
	char *p, *q,temp;
	int length;
	for (length = 0; string1[length] != '\0'; length++);
	for (p = string1, q = string1 + length - 1; p < q; p++, q--)
	{
		temp = *p;
		*p = *q;
		*q = temp;
	}
	return string1;
}
//Function to copy a string into another string
void strcpy(char *string2, char *string1)
{
	while ((*string2++ = *string1++) != '\0');
}
//Function to concatenate a string to another string
void strcat(char *string1, char *string2)
{
	while ((*string1++) != '\0'); 
	*string1--;
	while ((*string1++ = *string2++) != '\0');
}
//Function to compare two strings
int strcmp(char *string1, char *string2)
{
	while (*string1++ == *string2++)
	{
		if ((*string1) == '\0')
			return 0;
	}
	*string1--;
	*string2--; 
	if ((*string1 - *string2) > 0)
		return 1;
	else
		return -1;
}
int main()
{
	char *string1,*string2;
	int choice,check,size1,size2;
	printf("Enter length of string\n");
	scanf("%d", &size1);
	string1 = (char*)malloc(sizeof(char)*size1);
	printf("Enter string to carry out string functions\n");
	scanf("%s", string1);
		printf("Enter choice 1.strrev 2.strcpy 3.strcat 4.strcmp\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Reversed string is %s\n", strrev(string1));
			break;
		case 2:
			printf("Enter length of Second string\n");
			scanf("%d", &size2);
			string2 = (char*)malloc(sizeof(char)*size2);
			strcpy(string2, string1);
			printf("Copied string is %s\n", string2);
			free(string2);
			break;
		case 3:
			printf("Enter length of Second string\n");
			scanf("%d", &size2);
			string2 = (char*)malloc(sizeof(char)*size2);
			printf("Enter string2\n");
			scanf("%s", string2);
			strcat(string1, string2);
			printf("Final string after concatination is %s\n", string1);
			free(string2);
			break;
		case 4:
			printf("Enter length of Second string\n");
			scanf("%d", &size2);
			string2 = (char*)malloc(sizeof(char)*size2);
			printf("Enter string2\n");
			cin >> string2;
			check = strcmp(string1, string2);
			if (check == 0)
				printf("Both strings are equal\n");
			else if (check == -1)
				printf("%s is less than %s\n", string1, string2);
			else
				printf("%s is greater than %s\n", string1, string2);
			free(string2);
			break;
	}
	free(string1);
	getchar();
	return 0;
}