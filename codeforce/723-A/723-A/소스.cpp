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

		vector<ll> arr(2 * n);
		for (int i = 0; i < 2 * n; i++)
			cin >> arr[i];

		sort(arr.begin(), arr.end());
		
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " " << arr[i+n] << " ";
		}
		cout << "\n";
	}
}