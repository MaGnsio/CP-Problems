/**
 *    author:  MaGnsi0
 *    created: 17.12.2024 22:06:35
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6 + 6, OO = 2e8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int64_t> a(n), b(n), c(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    vector<int64_t> d(N, OO), dp(N, 0);
    for (int i = 0; i < n; ++i) {
        d[a[i]] = min(d[a[i]], a[i] - b[i]);
    }
    for (int i = 1; i < N; ++i) {
        d[i] = min(d[i], d[i - 1]);
    }
    for (int i = 1; i < N; ++i) {
        if (d[i] == OO) { continue; }
        dp[i] = (i - d[i] >= 0 ? dp[i - d[i]] : 0) + 1;
    }
    //d min(a[i]), d min(a[i])
    //(a[i], b[i]) => d[i] = a[i] - b[i]
    // => c[j] - x * d[i] < a[i] => c[j] - a[i] < x * d[i] => (c[j] - a[i]) / d[i] < x
    // => c[j] = c[j] - x * d[i]
    // c[0] => 10 => 9 => 8 => 6 => 4
    // c[1] => 4
    // c[2] => 7 => 5 => 2
    // c[i] >= x dec y
    int64_t ans = 0;
    for (int i = 0; i < m; ++i) {
        if (c[i] < N) {
            ans += 2 * dp[c[i]];
        } else {
            int64_t A = N - 1, C = c[i], D = d[N - 1];
            int64_t x = (C - A + D - 1) / D;
            if (x <= 0) { continue; }
            ans += 2 * (x + dp[C - x * D]);
        }
    }
    cout << ans;
}
