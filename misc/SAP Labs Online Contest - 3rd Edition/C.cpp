/**
 *    author:  MaGnsi0
 *    created: 13.12.2021 18:15:06
**/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << "\n";
        return 0;
    }
    if (n == 2) {
        cout << k * (k - 1) % MOD << "\n";
        return 0;
    }
    vector<long long> a(n + 1);
    a[1] = k;
    for (int i = 2; i <= n; ++i) {
        a[i] = a[i - 1] * (k - 1) % MOD;
    }
    vector<long long> dp(n);
    dp[1] = 0;
    for (int i = 2; i < n; ++i) {
        dp[i] = (a[i] - dp[i - 1] + MOD) % MOD;
    }
    long long x = dp[n - 2];
    long long y = a[n - 1] - x;
    long long res = (x * (k - 1) % MOD + y * (k - 2) % MOD) % MOD;
    cout << res << "\n";
}
