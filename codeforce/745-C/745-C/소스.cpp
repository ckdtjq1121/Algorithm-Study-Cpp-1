#include<bits/stdc++.h>

using namespace std;

int psum0[401][401];
int psum1[401][401];

int sum(int y1, int x1, int y2, int x2, int type)
{
	x1--;
	y1--;
	int a, b, c, d;

	if (type == 1)
	{
		a = psum1[y2][x2];
		if (y1 >= 0)
			b = psum1[y1][x2];
		else
			b = 0;

		if (x1 >= 0)
			c = psum1[y2][x1];
		else
			c = 0;

		if (x1 >= 0 && y1 >= 0)
			d = psum1[y1][x1];
		else
			d = 0;
	}
	else
	{
		a = psum0[y2][x2];
		if (y1 >= 0)
			b = psum0[y1][x2];
		else
			b = 0;

		if (x1 >= 0)
			c = psum0[y2][x1];
		else
			c = 0;

		if (x1 >= 0 && y1 >= 0)
			d = psum0[y1][x1];
		else
			d = 0;
	}
	return a - b - c + d;
}

int need(int y1, int x1, int y2, int x2)
{
	int plus = 0, minus = 0;
	minus = sum(y1 + 1, x1 + 1, y2 - 1, y2 - 1, 0);
	plus += sum(y1 + 1, x1, y2 - 1, x2, 0);
	plus += sum(y1, x1 + 1, y2, x2 - 1, 0);
	plus -= 2 * minus;

	minus = sum(y1 + 1, x1 + 1, y2 - 1, y2 - 1, 1);
	return plus + minus;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, m;
		cin >> n >> m;
		char grid[401][401];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> grid[i][j];
			}
		}

		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '1')
				{
					psum1[i][j] = 1;
					psum0[i][j] = 0;
				}
				else
				{
					psum1[i][j] = 0;
					psum0[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				psum1[i][j] += psum1[i][j - 1];
				psum0[i][j] += psum0[i][j - 1];
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				psum1[i][j] += psum1[i-1][j];
				psum0[i][j] += psum0[i-1][j];
			}
		}


	}
}