#include <bits/stdc++.h>
using namespace std;
struct Comparator {
	vector<int>& group;
	int t;
	Comparator(vector<int>& _group, int _t) :group(_group), t(_t) {
		group = _group; t = _t;
	}
	bool operator() (int a, int b) {
		if (group[a] != group[b])return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};
vector<int> getSuffixArray(const string& s) {
	int n = s.size();
	int t = 1;
	vector<int> group(n + 1);
	for (int i = 0; i < n; i++)group[i] = s[i];
	group[n] = -1;
	vector<int> perm(n);
	for (int i = 0; i < n; i++)perm[i] = i;
	while (t < n) {
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		t *= 2;
		if (t >= n)break;
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for (int i = 1; i < n; i++)
			if (compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		group = newGroup;
	}
	return perm;
}
int lcp[200001], Rank[200001];

vector<int> getLCP(const string &s)
{
	int n = s.size();
	vector<int> suffixArray = getSuffixArray(s);
	
	
	vector<int> rank(n);
	for (int i = 0; i < n; i++)
		rank[suffixArray[i]] = i;

	vector<int> lcp(n);
	int len = 0;
	for (int i = 0; i < n; i++) {
		int k = rank[i];
		if (k) {
			int j = suffixArray[k - 1];
			while (s[j + len] == s[i + len])
				len++;

			lcp[k] = len;
		}
		if (len)len--;
	}

	return lcp;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	
	int ans = 0;
	vector<int> lcp = getLCP(s);
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, lcp[i]);
	}

	cout << ans << '\n';
}