#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int j;
int* HexToBin(char h[])
{
	int i;
	int *a = (int*)malloc(sizeof(int) * 100);
	char t;
	for (i = 0; h[i] != '\0'; i=i+1)
	{
		t = h[0];
		if ((t == '0') || (t == '1') || (t == '2') || (t == '3') || (t == '4') || (t == '5') || (t == '6') || (t == '7'))
			a[j++] = 0;
		else
			a[j++] = 1;
		t = h[i];
		if ((t == '0') || (t == '1') || (t == '2') || (t == '3') || (t == '8') || (t == '9') || (t == 'A') || (t == 'B'))
			a[j++] = 0;
		else
			a[j++] = 1;
		t = h[i];
		if ((t == '0') || (t == '1') || (t == '4') || (t == '5') || (t == '8') || (t == '9') || (t == 'C') || (t == 'D'))
			a[j++] = 0;
		else
			a[j++] = 1;
		t = h[i];
		if ((t == '0') || (t == '2') || (t == '4') || (t == '6') || (t == '8') || (t == 'A') || (t == 'C') ||(t=='E'))
			a[j++] = 0;
		else
			a[j++] = 1;

	}
	return a;
}
int* compliment(int a[])
{
	int i;
	int *b = (int*)malloc(sizeof(int) * 100);
	for (i = 0; i < j; i++)
	{
		if (a[i] == 0)
			b[i] = 1;
		else
			b[i] = 0;
	}
	return b;
}
char* BinToHex(int b[])
{
	char *s = (char*)malloc(sizeof(char) * 10);
	int k = 0, val, i;
	for(i = 0 ; i < j; i = i + 4)
	{
		val = (b[i] * 8) + (b[i + 1] * 4) + (b[i + 2] * 2) + (b[i + 3] * 1);
		if (val < 10)
			s[k++] = val + 48;
		else
			s[k++] = val + 55;
	}
	return s;
}
int* bitShift(int a[])
{
	int i,d,n;
	int *b = (int*)malloc(sizeof(int) * 100);
	printf("enter 1.right shift 2.left shift\n");
	scanf("%d", &d);
	printf("enter number of bits you want to shift\n");
	scanf("%d", &n);
	if (d == 1)
	{
		for (i = j - d - 1; i >= 0; i--)
		{
			b[i + d] = a[i];
		}
		for (i = 0; i < d; i++)
			b[i] = 0;
	}
	else
	{

	}
	return b;
}
int main()
{
	char h[10],*s1;
	int *a,i,*b,*c;
	printf("enter a hexadecimal value");
	scanf("%s", h);
	a = HexToBin(h);
	for(i=0;i<j;i++)
		printf("%d",*(a+i));
	printf("\n");
	b = compliment(a);
	for (i = 0; i < j; i++)
		printf("%d", *(b + i));
	printf("\n");
	s1 = BinToHex(b);
	for (i = 0; s1[i] != '\0'; i++)
		printf("%c", s1[i]);
	printf("\n");
	c = bitShift(a);
	for (i = 0; i < j; i++)
		printf("%d", *(c + i));
	printf("\n");
	return 0;
}