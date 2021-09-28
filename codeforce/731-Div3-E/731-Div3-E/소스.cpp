#include<bits/stdc++.h>

using namespace std;
const int INF = 2000000000;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> loc(k);
		for (int i = 0; i < k; i++)
		{
			cin >> loc[i];
			loc[i]--;
		}
		vector<int> temper(k);
		for (int i = 0; i < k; i++)
		{
			cin >> temper[i];
		}

		vector<int > data(n, INF);
		for (int i = 0; i < k; i++)
		{
			data[loc[i]] = temper[i];
		}

		int p = INF;
		vector<int> L(n);
		for (int i = 0; i < n; i++)
		{
			p = min(p + 1, data[i]);
			L[i] = p;
		}
		p = INF;
		vector<int> R(n);
		for (int i = n-1; i >= 0; i--)
		{
			p = min(p + 1, data[i]);
			R[i] = p;
		}

		for (int i = 0; i < n; i++)
			cout << min(L[i], R[i]) << " ";
		cout << "\n";
	}
}