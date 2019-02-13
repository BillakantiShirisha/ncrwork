#include<stdio.h>
struct time
{
	int hrs, mins, secs;
};
int main()
{
	struct time s;
	printf("enter hrs,mins and secs\n");
	scanf("%d%d%d", &s.hrs, &s.mins, &s.secs);
	printf("Time = %d:%d:%d\n", s.hrs, s.mins, s.secs);
	return 0;
}