/**
 *    author:  MaGnsi0
 *    created: 17.11.2024 18:21:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int k; cin >> k;
        vector<int64_t> H(n), X(n);
        for (int i = 0; i < n; ++i) {
            cin >> H[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> X[i];
        }
        function<int64_t(int64_t, int64_t, int64_t)> get_l = [&](int64_t h, int64_t x, int64_t y) {
            /*
            *     y * (m - (x - l)) >= h
            *  => y * m - y * x + y * l >= h
            *  => l >= (h / y) - m + x
            */
            int64_t l = ((h + y - 1) / y) - m + x;
            return l;
        };
        function<int64_t(int64_t, int64_t, int64_t)> get_r = [&](int64_t h, int64_t x, int64_t y) {
            /*
            *     y * (m - (r - x)) >= h
            *  => y * m - y * r + y * x >= h
            *  => r <= m + x - (h / y)
            */
            int64_t r = m + x - ((h + y - 1) / y);
            return r;
        };
        function<bool(int64_t)> F = [&](int64_t y) {
            map<int64_t, int> f;
            for (int i = 0; i < n; ++i) {
                int l = get_l(H[i], X[i], y);
                int r = get_r(H[i], X[i], y);
                if (l > r) { continue; }
                f[l]++, f[r + 1]--;
            }
            int64_t have = 0;
            for (auto [_, e] : f) {
                have += e;
                if (have >= k) { return true; }
            }
            return false;
        };
        int64_t low = 1, high = 1e9, ans = -1;
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
