#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, m;
		cin >> n >> m;
		vector<string> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		vector<string> b(n - 1);
		for (int i = 0; i < n - 1; i++)
			cin >> b[i];
		
		vector<vector<int> > cnt(m);
		for(int i = 0; i < m; i++)
			cnt[i] = vector<int>(26, 0);
		for (int i = 0; i < n; i++)
		{
			
			for (int j = 0; j < m; j++)
			{
				int c = arr[i][j] - 'a';
				cnt[j][c]++;
			}
		}

		vector<vector<int> > cntb(m);
		for (int i = 0; i < m; i++)
			cntb[i] = vector<int>(26, 0);


		for (int i = 0; i < n-1; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int c = b[i][j] - 'a';
				cntb[j][c]++;
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (cnt[i][j] - cntb[i][j] == 1)
				{
					char c = 'a' + j;
					cout << c;
					break;
				}
			}
		}
		cout << "\n";
	}
}