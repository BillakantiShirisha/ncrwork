#include<iostream>
using namespace std;
void buildHeap(int a[], int i, int n)
{
	int temp = a[i],c;
	for (; (2 * i + 1) < n; i = c)
	{
		c = (2 * i) + 1;
		if (c + 1 < n && a[c + 1] > a[c])
			c++;
		if (a[c] > temp)
			a[i] = a[c];
		else
			break;
	}
	a[i] = temp;
}
void heapsort(int a[],int n)
{
	int i, j,t;
	for (i = (n / 2) - 1; i >= 0; i--)
		buildHeap(a,i, n);
	for (j = 1; j <= n - 1; j++)
	{
		t = a[0];
		a[0] = a[n - j];
		a[n - j] = t;
		buildHeap(a, 0, n - j);
	}

}
int main()
{
	int i, j, a[10], n, loc, t;
	cout << "Enter number of elements\n";
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	heapsort(a,n);
	for (i = 0; i < n; i++)
		cout << a[i] << endl;
	return 0;
}