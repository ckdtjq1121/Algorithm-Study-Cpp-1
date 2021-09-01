#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <memory.h>
using namespace std;

//// brute force
//bool ismatchWildcard(const string& W, const string& S)
//{
//	int pos = 0;
//	while (pos < W.size() && pos < S.size() &&
//		(W[pos] == '?' || W[pos] == S[pos]))
//		pos++;
//
//	if (pos == W.size())
//		return pos == S.size();
//
//	if (W[pos] == '*')
//		for (int skip = 0; pos + skip < S.size(); skip++)
//		{
//			if (ismatchWildcard(W.substr(pos + 1, W.size()), S.substr(pos + skip, S.size())))
//				return true;
//		}
//
//	return false;
//}
string W, S;
int cashe[101][101];
// memoization
bool ismatchWildcard(int w, int s)
{
	int& ret = cashe[w][s];
	// already search
	if (ret != -1) return ret;
	// successful search
	if (w == W.size())
		return ret = (s == S.size());


	if (w < W.size() && s < S.size() &&
		(W[w] == '?' || W[w] == S[s]))
		return ismatchWildcard(w + 1, s + 1);

	if (W[w] == '*')
		return ret = ismatchWildcard(w + 1, s) || (s < S.size() && ismatchWildcard(w, s + 1));

	return ret = 0;
}
int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		// input
		cin >> W;

		int n;
		cin >> n;

		// ans that sorted by askii
		set<string> ans;
		for (int j = 0; j < n; j++)
		{
			for (int j = 0; j < 101; j++)
				for (int k = 0; k < 101; k++)
					cashe[j][k] = -1;

			cin >> S;
			if (ismatchWildcard(0, 0))
				ans.insert(S);
		}

		// output 
		int ans_size = ans.size();
		for (int j = 0; j < ans_size; j++)
		{
			cout << *ans.begin() << endl;
			ans.erase(ans.begin());
		}
	}
}