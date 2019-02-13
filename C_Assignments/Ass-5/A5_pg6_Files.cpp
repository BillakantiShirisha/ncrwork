#include<stdio.h>
int main(int argc, char *argv[])
{
	int i; char c;
	/*for (i = 1; i < argc; i++)
		printf("%s\n", argv[i]);*/
	FILE *fp;
	FILE *fp1;
	fp = fopen(argv[1], "w");
	if (fp == NULL)
	{
		printf("file is not created\n");
		return -1;
	}
	while ((c = getchar()) != EOF)
		putc(c, fp);
	fclose(fp);
	fp1 = fopen(argv[1], "r");
	if (fp1 == NULL)
	{
		printf("Cannot open the file\n");
		return -1;
	}
	while (!feof(fp1))
	{
		//c = getc(fp1);
		printf("%c", getc(fp1));
	}
	fclose(fp1);
	return 0;
}