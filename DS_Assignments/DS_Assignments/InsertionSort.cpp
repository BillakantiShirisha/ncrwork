#include<iostream>
using namespace std;
int main()
{
	int i, j, a[10], n, temp, t;
	cout << "Enter number of elements\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 1; i <= n - 1; i++)
	{
		j = i - 1;
		temp = a[i];
		while ((j >= 0) && (a[j] > temp))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	for (i = 0; i < n; i++)
		cout << a[i] << endl;
	return 0;
}