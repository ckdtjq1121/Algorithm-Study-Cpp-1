#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> perm(9);
	string p = "";
	for (int i = 0; i < 9; i++)
	{
		cin >> perm[i];
		p += (perm[i] + '0');
	}

	string a = "123456780";

	// don't need to move puzzle
	if (p == a)
	{
		cout << 0 << "\n";
		return 0;
	}

	map<string, int> dist;
	queue<string> q;
	q.push(p);
	dist[p] = 0;
	while (!q.empty())
	{
		string u = q.front();
		q.pop();

		int cost = dist[u];
		int idx = u.find('0'); // index of empty space (0)

		// can be moved delta index
		int di[9][4] =
		{
			{1, 3, 0, 0},
			{-1, 1, 3, 0},
			{-1, 3, 0, 0},

			{-3, 1, 3, 0},
			{-3, -1, 1, 3},
			{-3, -1, 3, 0},

			{-3, 1, 0, 0},
			{-3, -1, 1, 0},
			{-3, -1, 0, 0}
		};

		for (int i = 0; i < 4; i++)
		{
			int ni = idx + di[idx][i];
			if (idx != ni)
			{	
				// make v (new state puzzle)
				swap(u[idx], u[ni]);

				if (dist.count(u) == 0)
				{
					// find sorted puzzle
					if (u == a)
					{
						cout << cost + 1 << "\n";
						return 0;
					}

					dist[u] = cost + 1;
					q.push(u);
				}
				// roll back to u
				swap(u[idx], u[ni]);
			}
		}
	}

	// can't find sorted puzzle
	cout << -1 << "\n";
}