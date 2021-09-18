#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;

char board[10001][501];
int r, c;

// greedy upside end point --> greedy path(?)
int cango(int y, int x)
{
	if (board[y][x] == 'x' || y == 0 || y == r + 1)
		return INF;


	if (x == c)
		return y;

	// up side
	int ret = cango(y - 1, x + 1);
	int how = -1;
	// mid side
	if (ret != INF)
	{
		ret = cango(y, x + 1);
		how = 0;
	}
	// down side
	if (ret != INF)
	{
		ret = cango(y + 1, x + 1);
		how = -1;
	}

	cout << y << " " << x << " " << ret << "\n";
	return ret;
}
//vector<int> makegreedyWay(int y, int x)
//{
//
//}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> board[i][j];
		}
	}

	cout << cango(1, 1) << "\n";
	cout << cango(5, 3) << "\n";
}