#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int move(int left, int right, int delta)
{
	for (int i = 0; i < delta; i++)
	{
		int tmp = arr[left];
		for (int j = left; j < right; j++)
		{
			//cout << i << " " << j << "\n";
			arr[j] = arr[j + 1];
		}
		arr[right] = tmp;
	}

	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		cin >> n;
		arr.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		vector<vector<int>> ans;
		for (int i = 1; i <= n; i++)
		{
			int mn = arr[i];
			int loc = i;
			for (int j = i+1; j <= n; j++)
			{
				if (mn > arr[j])
				{
					mn = arr[j];
					loc = j;
				}
			}

			int l = min(i, loc);
			int r = max(i, loc);
			if (l == r)
				continue;

			move(l, r, r - l);
			//for (int k = 1; k <= n; k++)
			//	cout << arr[k] << " ";
			//cout << "\n";

			vector<int> tmp;
			tmp.push_back(l);
			tmp.push_back(r);
			tmp.push_back(r - l);
			ans.push_back(tmp);
		
		}


		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";
			cout << "\n";
		}
	}
}