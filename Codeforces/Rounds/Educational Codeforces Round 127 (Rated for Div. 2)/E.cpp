/**
 *    author:  MaGnsi0
 *    created: 30.07.2022 07:05:50
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<string> dp(1 << n);
    for (int i = (1 << (n - 1)); i < (1 << n); ++i) {
        dp[i] = string(1, s[i - 1]);
    }
    for (int i = (1 << (n - 1)) - 1; i >= 1; --i) {
        dp[i] = string(1, s[i - 1]) + min(dp[2 * i], dp[2 * i + 1]) + max(dp[2 * i], dp[2 * i + 1]);
    }
    int ans = 1;
    for (int i = 1; i <  (1 << (n - 1)); ++i) {
        if (dp[2 * i] != dp[2 * i + 1]) {
            ans *= 2;
            ans %= MOD;
        }
    }
    cout << ans;
}
