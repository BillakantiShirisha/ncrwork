#include<iostream>
using namespace std;
class Matrix
{
	int **m;
public:
	friend void mult(Matrix &m, int n);
};
void mult(Matrix &m1, int s)
{
	int n,o;
	cin >> n >> o;
	m1.m = new int*[n];
	for (int i = 0; i < n; i++)
	{
		m1.m[i] = new int[o];
		for (int j = 0; j < o; j++)
			cin >> m1.m[i][j];
	}
	for (int k = 0; k < n; k++)
		for (int l = 0; l < o; l++)
		{
			m1.m[k][l] = s*m1.m[k][l];
			cout << m1.m[k][l]<<endl;
		}
}
int main()
{
	Matrix m1;
	int s1;
	cin >> s1;
	mult(m1, s1);
	return 0;
}