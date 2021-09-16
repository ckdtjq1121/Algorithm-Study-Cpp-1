#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int> > schedule(n);
	for (int i = 0; i < n; i++)
	{
		cin >> schedule[i].first >> schedule[i].second;
	}
	sort(schedule.begin(), schedule.end());

	priority_queue<int, vector<int>, greater<int> > pq;

	int ans = 1; // 	
	for(int i = 0; i < schedule.size(); i++)
	{
		// pop end schedule
		while (!pq.empty() && pq.top() <= schedule[i].first)
			pq.pop();

		// push start schedul
		pq.push(schedule[i].second);;
		ans = max(ans, (int)pq.size());
	}

	cout << ans << "\n";
}