#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int> > arr;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		arr.push(tmp);
	}


	long long ans = 0;
	int a = 0, b = 0;
	for (int i = 1; i < n; i++)
	{
		if (!arr.empty())
		{
			a = arr.top();
			arr.pop();
		}
		if (!arr.empty())
		{
			b = arr.top();
			arr.pop();
		}
		
		ans += (a + b);

		arr.push(a + b);
	}

	cout << ans << "\n";
}

