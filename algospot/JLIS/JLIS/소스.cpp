#include<bits/stdc++.h>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();

int n, m;
int cache[101][101];
int seqA[100];
int seqB[100];
int maxJLIS(int idxA, int idxB)
{
	int &ret = cache[idxA + 1][idxB + 1];
	if (ret != -1)
		return ret; 

	ret = 0;
	long long a = (idxA == -1 ? NEGINF : seqA[idxA]);
	long long b = (idxB == -1 ? NEGINF : seqB[idxB]);
	long long c = max(a, b);

	for (int i = idxA + 1; i < n; i++)
	{
		if (c < seqA[i])
			ret = max(ret, maxJLIS(i, idxB) + 1);
	}

	for (int i = idxB + 1; i < m; i++)
	{
		if (c < seqB[i])
			ret = max(ret, maxJLIS(idxA, i) + 1);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{	
		cin >> n >> m;

		for (int j = 0; j < n; j++)
			cin >> seqA[j];
	
		for (int j = 0; j < m; j++)
			cin >> seqB[j];

		memset(cache, -1, sizeof(cache));
	;
		cout << maxJLIS(-1, -1) << endl;
	}
}
