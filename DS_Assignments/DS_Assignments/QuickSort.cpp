#include<iostream>
using namespace std;
void quicksort(int a[], int low, int high)
{
	int pivot = a[low];
	int i, j,t;
	i = low + 1;
	j = high;
	if (low < high)
	{
		while (1)
		{
			while (i <= high && a[i] < pivot)
				i++;
			while (a[j] > pivot)
				j--;
			if (i < j)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			else
				break;
		}
		t = a[low];
		a[low] = a[j];
		a[j] = t;
		quicksort(a,low, j - 1);
		quicksort(a,j + 1, high);
	}
}
int main()
{
	int i, j, a[10], n, loc, t;
	cout << "Enter number of elements\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	quicksort(a, 0, n - 1);
	for (i = 0; i < n; i++)
		cout << a[i] << endl;
	return 0;
}