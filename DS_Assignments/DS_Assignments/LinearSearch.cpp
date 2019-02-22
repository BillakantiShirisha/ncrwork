#include<iostream>
using namespace std;
int lsearch(int a[],int n,int t)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (t == a[i])
		{
			return i+1;
		}
	}
	return -1;
}
int main()
{
	int i, a[10], n, t;
	cout << "Enter number of elements\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	cout << "Enter an element to search\n";
	cin >> t;
	cout << "Element found at location:" << lsearch(a,n,t);
	return 0;
}