#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	// Eratos
	vector<bool> prime(m + 1, true);
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i * i <= m; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= m; j = j + i)
				prime[j] = false;
		}
	}

	for (int i = n; i <= m; i++)
		if (prime[i])
			cout << i << "\n";
}