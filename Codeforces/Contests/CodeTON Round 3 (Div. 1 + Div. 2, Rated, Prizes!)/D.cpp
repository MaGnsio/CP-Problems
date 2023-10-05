/**
 *    author:  MaGnsi0
 *    created: 06.11.2022 17:38:35
**/
#include <bits/stdc++.h>

using namespace std;

int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m;
        cin >> n >> m;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t ans = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] % a[i]) {
                ans = 0;
                break;
            }
            int64_t x = a[i - 1] / a[i];
            vector<int64_t> b;
            for (int64_t j = 2; j * j <= x; ++j) {
                if (x % j == 0) {
                    b.push_back(j);
                }
                while (x % j == 0) {
                    x /= j;
                }
            }
            if (x > 1) {
                b.push_back(x);
            }
            int cnt = (int)b.size();
            int64_t val = 0;
            for (int j = 0; j < (1 << cnt); ++j) {
                int64_t y = a[i];
                for (int k = 0; k < cnt; ++k) {
                    if ((j >> k) & 1) {
                        y *= b[k];
                    }
                }
                if (__builtin_popcountll(j) & 1) {
                    val -= m / y;
                    val += MOD;
                    val %= MOD;
                } else {
                    val += m / y;
                    val %= MOD;
                }
            }
            ans *= val;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
