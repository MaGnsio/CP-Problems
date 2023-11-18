/**
 *    author:  MaGnsi0
 *    created: 08.10.2023 15:01:56
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n), P2(n + 1, 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        P2[i] = 2 * P2[i - 1] % MOD;
    }
    //turning on i gives you score >= b[i]
    map<int64_t, int64_t> mp;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            b[i - 1] = max(b[i - 1], a[j - 1]);
        }
        mp[b[i - 1]]++;
    }
    int64_t ans = 0, smaller = 0;
    for (auto [x, y] : mp) {
        int64_t val = P2[smaller] * (P2[y] + MOD - 1) % MOD;
        ans = (ans + x * val) % MOD;
        smaller += y;
    }
    cout << ans;
}
