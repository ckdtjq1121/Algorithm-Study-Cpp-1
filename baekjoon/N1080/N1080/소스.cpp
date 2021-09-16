#include<bits/stdc++.h>

using namespace std;
char A[50][50];
char B[50][50];
int change(int y , int x)
{
	for (int i = y; i < y + 3; i++)
	{
		for (int j = x; j < x + 3; j++)
		{
			if (A[i][j] == '1')
				A[i][j] = '0';
			else
				A[i][j] = '1';
		}
	}

	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> B[i][j];

	int ans = 0;
	for (int i = 0; i < n -2; i++)
	{
		for (int j = 0; j < m -2; j++)
		{
			if (A[i][j] != B[i][j])
			{
				change(i, j);
				ans++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] != B[i][j])
			{
				ans = -1;
			}
		}
	}

	cout << ans << "\n";
}


