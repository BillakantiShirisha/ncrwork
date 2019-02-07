#include<stdio.h>
int main()
{
	long int bin,r,i,j=0;
	int hex[16] = {0, 1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111};
	char h[10];
	printf("enter binary number\n");
	scanf("%ld", &bin);
	while (bin > 0)
	{
		r = bin % 10000;
	//	printf("%d\n", r);
		for (i = 0; i < 16; i++)
		{
			if (r == hex[i])
			{
				if (i < 10)
					h[j] = i + 48;
				else
					h[j] = i + 55;
				break;
			}
		}
		j++;
		bin = bin / 10000;
	}
	h[j] = '\0';
	for (i = j-1; i>=0; i--)
		printf("%c", h[i]);
	printf("\n");
	printf("enter a hexadecimal number\n");
	scanf("%s", h);
	for (i = 0; h[i] != '\0'; i++)
	{
		switch (h[i])
		{
		case '0':printf("0000");
			break;
		case '1':printf("0001");
			break;
		case '2':printf("0010");
			break;
		case '3':printf("0011");
			break;
		case '4':printf("0100");
			break;
		case '5':printf("0101");
			break;
		case '6':printf("0110");
			break;
		case '7':printf("0111");
			break;
		case '8':printf("1000");
			break;
		case '9':printf("1001");
			break;
		case 'A':printf("1010");
			break;
		case 'B':printf("1011");
			break;
		case 'C':printf("1100");
			break;
		case 'D':printf("1101");
			break;
		case 'E':printf("1110");
			break;
		case 'F':printf("1111");
			break;
		}

	}
	return 0;
}