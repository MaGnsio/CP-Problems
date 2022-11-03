/**
 *    author:  MaGnsi0
 *    created: 10.09.2022 19:12:22
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int64_t N, Q;
        cin >> N;
        vector<int64_t> x(N), y(N);
        for (int i = 0; i < N; ++i) {
            cin >> x[i] >> y[i];
        }
        int64_t x_sum = 0, y_sum = 0, xs_sum = 0, ys_sum = 0;
        for (int i = 0; i < N; ++i) {
            x_sum += x[i];
            x_sum %= MOD;
            y_sum += y[i];
            y_sum %= MOD;
            xs_sum += x[i] * x[i] % MOD;
            xs_sum %= MOD;
            ys_sum += y[i] * y[i] % MOD;
            ys_sum %= MOD;
        }
        cin >> Q;
        int64_t ans = 0;
        for (int i = 0; i < Q; ++i) {
            int64_t xp, yp;
            cin >> xp >> yp;
            ans += N * xp % MOD * xp % MOD;
            ans %= MOD;
            ans += xs_sum;
            ans %= MOD;
            ans -= 2 * xp * x_sum % MOD;
            ans += MOD;
            ans %= MOD;
            ans += N * yp % MOD * yp % MOD;
            ans %= MOD;
            ans += ys_sum;
            ans %= MOD;
            ans -= 2 * yp * y_sum % MOD;
            ans += MOD;
            ans %= MOD;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
