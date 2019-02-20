#include<iostream>
using namespace std;
int main()
{
	int i, j, a[10], n, loc, t;
	cout << "Enter number of elements\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n - 1; i++)
	{
		int loc = i,j = i + 1;
		while (j <= n - 1)
		{
			if (a[j] < a[loc])
				loc = j;
			j++;
		}
		t = a[i];
		a[i] = a[loc];
		a[loc] = t;
	}
	for (i = 0; i < n; i++)
		cout << a[i] << endl;
	return 0;
}