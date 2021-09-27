#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<char>> grid(n);
	for (int i = 0; i < n; i++)
	{
		grid[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}
	vector<vector<char>> rotated(n);
	for (int i = 0; i < n; i++)
	{
		rotated[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			cin >> rotated[i][j];
		}
	}

	// 90

	// 180

	// 270
}