#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 998244353;

int n, dp[1000001], S;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + i; j <= n; j += i) {
            dp[j]++;
        }
    }
    dp[0] = S = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i] + S) % MOD;
        S = (S + dp[i]) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}


//dp

// 2nÀ» ±æÀÌ°¡ °°Àº n½ÖÀ¸·Î ¹¬±â =
// 2nÀ» n-1½ÖÀ¸·Î ¹­°í 1½Ö ¹¬±â +
// 2n-2À» ±æÀÌ°¡ °°Àº n-1½ÖÀ¸·Î ¹¬±â