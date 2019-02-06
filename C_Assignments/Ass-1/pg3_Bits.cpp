#include<stdio.h>
int main()
{
	int val;
	int test = 0x000F, v1 = 0x00FF, v2 = 0xFF00, v3 = 0xFFF0, v4 = 0x000F;
	int r, r2;
	printf("enter hexadecimal number\n");
	scanf("%x", &val);

	r = val & test;
	//printf("%x\n", r);

	if ((r == 0xE) || (r == 0xD) || (r == 0xB) || (r == 0xF) || (r == 0x7))
		printf("Yes atleast 3 bits are set\n");
	else
		printf("Atleast 3 bits are not set\n");

	r = val & v1;
	r = r << 8;
	r2 = val & v2;
	r2 = r2 >> 8;
	printf("%x\n", r2 | r);


	r = val & v3;
	r = r >> 4;
	r2 = val & v4;
	r2 = r2 << 12;
	printf("%x", r | r2);
	return 0;
}