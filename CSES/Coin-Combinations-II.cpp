/**
 *    author:  MaGnsi0
 *    created: 19.12.2021 16:32:45
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp(N, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = a[i]; j < N; ++j) {
            dp[j] += dp[j - a[i]];
            dp[j] %= MOD;
        }
    }
    cout << dp[x];
}
