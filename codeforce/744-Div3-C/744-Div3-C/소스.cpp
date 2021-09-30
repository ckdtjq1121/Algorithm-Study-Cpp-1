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
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		priority_queue<pair<int, int>, vector<pair<int, int> >, less<> > pq;
		
		for (int i = 0; i < n; i++)
		{
			pq.push({ arr[i], i });
		}

		vector<pair<int, int> > ans;
		while (!pq.empty())
		{
			int a = pq.top().first;
			int idxa = pq.top().second;
			pq.pop();
			if (a == 0)
				break;

			if (pq.empty())
			{
				break;
			}

			int b = pq.top().first;
			int idxb = pq.top().second;
			pq.pop();

			if (b == 0)
				break;
			for (int i = 0; i < b; i++)
				ans.push_back({ idxa+1, idxb+1 });

			pq.push({ a - b, idxa });

		}

		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].first << " " << ans[i].second << "\n";
	}
}