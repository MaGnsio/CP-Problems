/**
 *    author:  MaGnsi0
 *    created: 26.11.2021 13:02:28
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        long long res = 0;
        for (int i = 0; i < m; ++i) {
            int l, r, v;
            cin >> l >> r >> v;
            res |= v;
        }
        for (int i = 0; i < n - 1; ++i) {
            res *= 2LL;
            res %= MOD;
        }
        cout << res % MOD << "\n";
    }
}
