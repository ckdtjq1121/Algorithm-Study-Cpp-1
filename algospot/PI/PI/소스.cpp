#include<bits/stdc++.h>

using namespace std;
int dp[100001];
const int INF = 987654321;
string pi;

int classify(int a, int b)
{
	bool level1 = true;
	for (int j = 0; j < b - a; j++)
	{
		if (pi[a] != pi[a + j])
			level1 = false;
	}
	if (level1)
	{
		return 1;
	}

	bool progressive = true;
	int gap = pi[a] - pi[a + 1];
	for (int j = 2; j < b - a; j++)
	{
		if (pi[a] - pi[a + 1] != pi[a + j - 1] - pi[a + j])
			progressive = false;
	}
	
	if (progressive && (gap == 1 || gap == -1))
	{
		return 2;
	}
	
	bool level4 = true;
	for (int j = 2; j < b - a; j++)
	{
		if (pi[a + j] != pi[j % 2 + a])
			level4 = false;
	}

	if (level4)
	{
		return 4;
	}

	if (progressive)
		return 5;

	return 10;
}
int minLevel(int begin)
{
	if (begin == pi.size())
		return 0;

	int& ret = dp[begin];
	if (ret != -1)
		return ret;

	// 3, 4, 5 글자 씩 난이도를 설정한다.
	ret = INF;
	for (int i = 3; i < 6; i++)
	{
		if (begin + i <= pi.size())
		{
			ret = min(ret, minLevel(begin + i) + classify(begin, begin + i));
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		memset(dp, -1, sizeof(dp));

		cin >> pi;

		cout << minLevel(0) << endl;
	}
}