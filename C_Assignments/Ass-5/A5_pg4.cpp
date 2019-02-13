#include<stdio.h>
int main()
{
	int x = 0x12345678;
	//int s;
	char *c;
	c= (char*)&x;
	//s = sizeof(x);
	printf("%x", c[0]);
	return 0;
}