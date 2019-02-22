#include<iostream>
using namespace std;
int Bsearch(int a[], int n, int t)
{
	int low = 0; 
	int high = n - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (t < a[mid])
			high = mid - 1;
		else if (t > a[mid])
			low = mid + 1;
		else
			return mid+1;
	}
	if (low > high)
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
	cout << "Element found at location:" << Bsearch(a, n, t);
	return 0;
}