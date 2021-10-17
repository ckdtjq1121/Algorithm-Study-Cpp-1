#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
#define int int64_t
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define debug(x) cout << (#x) << ": " << (x) << '\n'

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

using vi = vector<int>;
using vp = vector<pii>;
using vvi = vector<vi>;
using vvp = vector<vp>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LNF = 1e18 + 7;

template<typename T> T _read() { T i; cin >> i; return i; }
template<typename...T> tuple<T...> _reads() { return { _read<T>()... }; }
//template<typename T, size_t...I> void _write(const T& i, index_sequence<I...>) { (..., (cout << (I ? " " : "") << get<I>(i))); }
template<typename...T> void _writes(tuple<T...> i) { _write(i, make_index_sequence<sizeof...(T)>()); }
template<typename T> T max(vector<T> v) { return *max_element(all(v)); }
template<typename T> T min(vector<T> v) { return *min_element(all(v)); }
template<typename T> istream& operator>> (istream& in, vector<T>& i) { for (auto& i : i) in >> i; return in; }
template<typename T, typename U> istream& operator>> (istream& in, pair<T, U>& i) { in >> i.X >> i.Y; return in; }
template<typename...T> istream& operator>> (istream& in, tuple<T...>& i) { i = _reads<T...>(); return in; }
template<typename T> ostream& operator<< (ostream& out, vector<T> i) { for (auto& i : i) out << i << ' '; return out; }
template<typename T, typename U> ostream& operator<< (ostream& out, pair<T, U> i) { out << i.X << ' ' << i.Y; return out; }
template<typename...T> ostream& operator<< (ostream& out, tuple<T...> i) { _writes(i); return out; }

bool compare(vector<int> a, vector<int> b)
{
	return a[a[0]] < b[b[0]];
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		int n, num;
		cin >> n;
		vector<vector<int>> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			a[i] = vector<int>(num);
			for (int j = 0; j < num; j++)
				cin >> a[i][j];
		}

		vp range(n);
		for (int i = 0; i < n; i++)
		{
			int start = 0; // init power in ith cave
			int cur = 0; // when find jth monster of ith cave, current power
			for (int j = 0; j < a[i].size(); j++)
			{
				cur = start + j;

				if (cur < a[i][j] + 1)
					start += a[i][j] + 1 - cur;
			}

			range[i].first = start; // init power in ith cave
			range[i].second = start + a[i].size();	//after beat last monster of ith cave, current power
		}
		sort(all(range)); // compare start power

		int ans = range[range.size() -1].first;
		for (int i = (int)range.size() - 2; i >= 0; i--)
		{
			if (range[i].second < range[i + 1].first) // remove gap between ith cave, (i+1)th cave
			{
				int diff = range[i + 1].first - range[i].second;

				range[i].first += diff;
				range[i].second += diff;
			}

			ans = min(ans, range[i].first);
		}

		cout << ans << "\n";
	}
}