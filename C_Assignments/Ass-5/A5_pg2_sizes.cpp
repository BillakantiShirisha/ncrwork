#include<stdio.h>
struct s
{
	int data;
	char ch;
};
union u
{
	int d;
	char ch;
};
int main()
{
	struct s s1;
	union u u1;
	printf("sizeof struct = %d\nsize of union=%d\n", sizeof(s1), sizeof(u1));
	return 0;
}