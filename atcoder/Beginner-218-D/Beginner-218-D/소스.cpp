#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<pair<int, int> > > group(n);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		bool dodo = false;
		for (int j = 0; j < k; j++)
		{
			if (group[j][0].first == x)
			{
				group[j].push_back(make_pair(x, y));
				dodo = true;
				break;
			}
		}

		if (!dodo)
		{
			k++;
			group[k].push_back(make_pair(x, y));
		}
	}

	for (int i = 0; i < n; i++)
	{
		sort(group[i].begin(), group[i].end());
	}


}