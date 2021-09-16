#include<bits/stdc++.h>

using namespace std;
const int INF = 987654321;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//int testCase;
	//cin >> testCase;

	//for (; testCase > 0; testCase--)
	//{
		// A
		//int n;
		//cin >> n;
		//if (n % 2 == 1)
		//{
		//	cout << 2 << " " << n - 1 << "\n";
		// 
		// n - 1  n
		//}
		//else
		//{
		//	cout << 2 << " " << n << "\n";
		//}

		// B
		//int n;
		//cin >> n;
		//string a, b;
		//cin >> a >> b;
		//vector<bool> canGo(n, true);
		//int ans = 0;
		//for (int i = 0; i < n; i++)
		//{
		//	if (canGo[i] && a[i] == '0' && b[i] == '1')
		//	{
		//		ans++;
		//		canGo[i] = false;
		//	}
		//	else if (i > 0 && canGo[i - 1] && a[i - 1] == '1' && b[i] == '1')
		//	{
		//		ans++;
		//		canGo[i - 1] = false;
		//	}
		//	else if (i + 1 < n && canGo[i + 1] && a[i + 1] == '1' && b[i] == '1')
		//	{
		//		ans++;
		//		canGo[i + 1] = false;
		//	}
		//}
		//cout << ans << "\n";

		// C
		int n, m;
		cin >> n >> m;
		vector<int > cntStrong(n + 1, 0);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			
			if (a > b)
				cntStrong[b]++;
			else
				cntStrong[a]++;

		}

		// cnt people that will be alive
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cntStrong[i] == 0)
				ans++;
		}

		int q;
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			int type;
			cin >> type;
			// add
			if (type == 1)
			{
				int a, b;
				cin >> a >> b;

				if (a > b)
				{
					if (cntStrong[b] == 0)
						ans--;

					cntStrong[b]++;
				}
				else
				{
					if (cntStrong[a] == 0)
						ans--;

					cntStrong[a]++;
				}

			}
			// remove
			else if (type == 2)
			{
				int a, b;
				cin >> a >> b;

				if (a > b)
				{
					cntStrong[b]--;

					if (cntStrong[b] == 0)
						ans++;
				}
				else
				{
					cntStrong[a]--;

					if (cntStrong[a] == 0)
						ans++;
				}
			}
			// present ans
			else if (type == 3)
			{
				cout << ans << "\n";
			}
		}



		
		// D

	//}
}