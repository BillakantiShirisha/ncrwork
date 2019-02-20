#include<iostream>
using namespace std;
int main()
{
	int i, j, a[10], n,flag,t;
	cout << "Enter number of elements\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	for (i = 0; i < n; i++)
		cout << a[i] << endl;
	return 0;
}