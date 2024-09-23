/**
 *    author:  MaGnsi0
 *    created: 23.09.2024 20:52:02
**/
#include <bits/stdc++.h>

using namespace std;


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64_t random(int64_t x, int64_t y) {
    return uniform_int_distribution<int64_t>(x, y)(rng);
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        function<bool(int, int, int)> F = [&](int i, int j, int k) {
            return 1LL * (y[j] - y[i]) * (x[k] - x[j]) == 1LL * (y[k] - y[j]) * (x[j] - x[i]);
        };
        function<int(int, int)> on_line = [&](int i, int j) {
            int res = 0;
            for (int k = 0; k < n; ++k) {
                res += F(i, j, k);
            }
            return n - res;
        };
        int ans = n;
        for (int _ = 0; _ < 100; ++_) {
            int i = random(0, n - 1);
            int j = random(0, n - 1);
            while (i == j) {
                j = random(0, n - 1);
            }
            ans = min(ans, on_line(i, j));
        }
        cout << ans << "\n";
    }
}
