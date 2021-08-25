#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
bool dp[101][101];  // dp cashe
int grid[101][101]; // grid gameboard
int n;
bool canReachPoint(int y, int x)
{
	// already Reach
	if (dp[y][x] != false)
		return false;

	// range out of grid
	if (y >= n || x >= n)
		return false;

	// reach is true
	dp[y][x] = true;

	// reach EndPoint
	if (y == n - 1 && x == n - 1)
		return true;

	int delta = grid[y][x];
	bool ret = false;

	return ret = canReachPoint(y + delta, x) || canReachPoint(y, x + delta);
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		// input
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> grid[i][j];

		// init DP memorization cashe
		for (int k = 0; k < 101; k++)
			for (int j = 0; j < 101; j++)
				dp[k][j] = false;

		// output
		if (canReachPoint(0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}