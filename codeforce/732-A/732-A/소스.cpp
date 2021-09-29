#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int> b(n);
		for (int i = 0; i < n; i++)
			cin >> b[i];

		vector<int> diff(n);
		for (int i = 0; i < n; i++)
			diff[i] = a[i] - b[i];

		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += diff[i];

		if (sum != 0)
		{
			cout << -1 << "\n";
			continue;
		}
		vector<pair<int, int> > ans;
		while (true)
		{

			int minus = -1, plus = -1;
			for (int j = 0; j < n; j++)
			{
				if (diff[j] < 0)
				{
					minus = j;
					break;
				}
			}
			for (int j = 0; j < n; j++)
			{
				if (diff[j] > 0)
				{
					plus = j;
					break;
				}
			}
			if (minus == -1 || plus == -1)
				break;

			int num = min(diff[plus], abs(diff[minus]));
			for (int j = 0; j < num; j++)
			{
				ans.push_back({ plus + 1, minus + 1 });
			}

			diff[plus] -= num;
			diff[minus] += num;
		
		}

		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].first << " " << ans[i].second << "\n";
	}
}