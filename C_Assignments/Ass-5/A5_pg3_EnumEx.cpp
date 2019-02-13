#include<stdio.h>
int main()
{
	enum operations{add=1,sub,mul,div};
	int op,a,b,c;
	printf("enter a and b\n");
	scanf("%d%d", &a, &b);
	printf("enter operations 1.add 2.sub 3.mul 4.div\n");
	scanf("%d", &op);
	switch (op)
	{
	case add: c = a + b;
		break;
	case sub:c = a - b;
		break;
	case mul:c = a * b;
		break;
	case div:c = a / b;
		break;
	}
	printf("result = %d", c);
	return 0;
}