/**
 *    author:  MaGnsi0
 *    created: 17.07.2023 12:05:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("shops.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m, k;
        cin >> n >> m >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        function<int64_t(int64_t)> F = [&](int64_t x) {
            int64_t res = m * (x / (m + 1)) + (x % (m + 1));
            return res;
        };
        if (F(n) >= k) {
            cout << 0 << "\n";
            continue;
        }
        int64_t ans = k * a[0];
        for (int i = 0; i < n; ++i) {
            int64_t x = F(i) + F(n - i - 1);
            assert(x < k);
            ans = min(ans, (k - x) * a[i]);
        }
        cout << ans << "\n";
    }
}
