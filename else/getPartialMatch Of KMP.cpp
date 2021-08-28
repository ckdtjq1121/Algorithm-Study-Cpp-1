#include <iostream>
#include <string>
#include <vector>
using namespace std;

// S의 (접두사 == 접미사) 실패함수
vector<int> getPartialMatch(string &S)
{
	int n = S.size();
	vector<int> pi(n, 0);

	for (int i = 1, j = 0; i < n; i++)
	{
		if(j > 0 && S[i] != S[j])
			j = pi[j - 1];

		if (S[i] == S[j])
			pi[i] = ++j;
	}

	return pi;
}
