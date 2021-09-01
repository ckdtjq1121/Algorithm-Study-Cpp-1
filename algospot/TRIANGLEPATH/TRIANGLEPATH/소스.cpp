#include<bits/stdc++.h>

using namespace std;
const int MAX = 101;
int triangle[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); // before - 36ms, after - 12ms

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int n;
		cin >> n;

		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= j; k++)
			{
				cin >> triangle[j][k];
			}
		}

		// memoization - optimal substructure
		// 이 방법은 지금 까지 어떤 경로로 내려왔는지는 상관이 없다. 앞으로 내려갈 경로만이 중요하다
		for (int j = 2; j <= n; j++)
		{
			triangle[j][1] += triangle[j - 1][1];
			for (int k = 2; k <= j; k++)
			{
				triangle[j][k] += max(triangle[j - 1][k - 1], triangle[j - 1][k]);
			}
		}

		// find maxPath
		int ret = 0;
		for (int k = 1; k <= n; k++)
			ret = max(ret, triangle[n][k]);


		cout << ret << "\n";
	}

}