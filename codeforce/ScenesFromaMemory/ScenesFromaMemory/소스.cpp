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

string s;

void solve()
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9')
		{
			cout << 1 << "\n";
			cout << s[i] << "\n";
			return;
		}
	}

	vector<bool> prime(100, true);
	for (int i = 2; i * i < 100; i++)
	{
		if (!prime[i])
			continue;

		for (int j = i * i; j < 100; j += i)
			prime[j] = false;
	}

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			string tmp = "";
			tmp += s[i];
			tmp += s[j];

			if (!prime[stoi(tmp)])
			{
				cout << 2 << "\n";
				cout << tmp << "\n";
				return;
			}
		}
	}

}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		int k;
		cin >> k;

		cin >> s;

		solve();
	}
}