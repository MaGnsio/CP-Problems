/**
 *    author:  MaGnsi0
 *    created: 08.09.2022 02:31:00
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k, w;
        cin >> n >> m >> k >> w;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        vector<int64_t> dp1(w + 1), dp2(w + 1);
        dp1[0] = dp2[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = w; j - a[i] >= 0; --j) {
                dp1[j] += dp1[j - a[i]];
                dp1[j] %= MOD;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = w; j - b[i] >= 0; --j) {
                dp2[j] += dp2[j - b[i]];
                dp2[j] %= MOD;
            }
        }
        int64_t ans = 0;
        for (int i = 0; i <= w; ++i) {
            if (abs(2 * i - w) <= k) {
                ans += dp1[i] * dp2[w - i];
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
}
