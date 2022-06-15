/**
 *    author:  MaGnsi0
 *    created: 15.03.2022 21:46:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, MOD;
    cin >> n >> MOD;
    vector<long long> F(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        F[i] = (F[i - 1] * i) % MOD;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (n - i + 1) * (F[n - i + 1] * F[i] % MOD);
        ans %= MOD;
    }
    cout << ans;
}
