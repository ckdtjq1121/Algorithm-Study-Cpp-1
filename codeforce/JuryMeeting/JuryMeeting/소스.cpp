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

const int MOD = 998244353;
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

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		int n;
		cin >> n;

		vi arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int mx = max(arr);
		int mx_cnt = count(all(arr), mx);
		int k = count(all(arr), mx - 1);
		// mx_cnt >= 2 ans = n!

		int ans = 1, sub = 1;
		for (int i = 1; i <= n; i++)
		{
			ans = ans * i % MOD;
			if (i != k + 1)
				sub = sub * i % MOD;
		}

		if (mx_cnt == 1)
			ans = (ans - sub + MOD) % MOD; // MOD된 값끼리의 차를 할때 MOD를 한번 더해주고 MOD를 한다
		
		cout << ans << "\n";
	}
}