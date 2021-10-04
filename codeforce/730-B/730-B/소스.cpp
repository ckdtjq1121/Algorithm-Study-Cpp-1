#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
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
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += (ll)arr[i];
		}

		sum %= n;

		cout << (n-sum) * sum << "\n";
	}
	
}