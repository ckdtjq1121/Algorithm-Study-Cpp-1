#include<bits/stdc++.h>

using namespace std;
vector<int> ans;
int k, n, m;
bool check(int a)
{
	if (a == 0)
	{
		ans.push_back(a);
		k++;
	}
	else if (a <= k)
		ans.push_back(a);
	else
		return false;

	return true;

}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		cin >> k >> n >> m;

		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		vector<int> b(m);
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}


		ans.clear();
		int mx = max(m, n);
		bool fail = false;
		int i = 0, j = 0;

		while (i < n || j < m)
		{	
			if (i < n && check(a[i]))
				i++;
			else if (j < m && check(b[j]))
				j++;
			else
			{
				fail = true;
				break;
			}
		}
		

		if (fail)
			cout << -1 << "\n";
		else
		{
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << " ";
			cout << "\n";
		}

	}
}