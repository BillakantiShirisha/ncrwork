#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
//template<>
template<class T>
int linear_search(T a[], int n, T ele)
{
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == ele)
			return 1;
	return 0;
}
//int linear_search<char*[],int,char*>
int linear_search(char *a[], int n, char *ele);
int linear_search(char *a[], int n, char *ele)
{
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(a[i], ele) == 0)
			return 1;
	return 0;
}
int main()
{
	int i; char n[20];
	int a[5] = { 10,11,12,13,14 };
	if (linear_search(a, 5, 11))
		cout << "element found" << endl;
	else
		cout << "ele not found" << endl;
	float b[5] = { 10.1,11.2,13.4,23.4 };
	if (linear_search(b, 5, 11.0f))
		cout << "element found" << endl;
	else
		cout << "ele not found" << endl;
	char *arr[3];
	for (i = 0; i < 3; i++)
	{
		printf("enter name\n");
		cin >> n;
		arr[i] = new char[strlen(n) + 1];
		strcpy(arr[i], n);
	}
	printf("enter name to search\n");
	cin >> n;
	if (linear_search(arr, 3, n))
		cout << "element found" << endl;
	else
		cout << "ele not found" << endl;
	return 0;
}