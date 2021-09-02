#include<bits/stdc++.h>

using namespace std;
const int MAX = 500;
int n;
vector<int> seq(MAX);
int cache[MAX];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		// input
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> seq[j];
		}
		// init;
		for (int j = 0; j < n; j++)
		{
			cache[j] = 1;
		}

		// tail recursion
		for (int j = n - 2; j >= 0; j--)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (seq[j] < seq[k])
					cache[j] = max(cache[j], cache[k] + 1);
			}
		}

		//// dubug - cache
		//for (int j = 0; j < n; j++)
		//	cout << cache[j] << " ";

		// ans
		int ans = 0;
		for (int j = 0; j < n; j++)
		{
			ans = max(ans, cache[j]);
		}
		cout << ans << endl;

	}
}