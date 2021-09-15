#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> time(n);
	for (int i = 0; i < n; i++)
		cin >> time[i];

	sort(time.begin(), time.end());

	int ans = time[0];
	for (int i = 1; i < n; i++)
	{
		time[i] += time[i - 1];
		ans += time[i];
	}
	
	cout << ans << "\n";
}