/**
 *    author:  MaGnsi0
 *    created: 22.02.2023 19:30:07
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e6, MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> F(N, 1), inv_F(N);
    for (int64_t i = 1; i < N; ++i) {
        F[i] = i * F[i - 1];
        F[i] %= MOD;
    }
    inv_F[N - 1] = power(F[N - 1], MOD - 2);
    for (int64_t i = N - 2; i >= 0; --i) {
        inv_F[i] = (i + 1) * inv_F[i + 1];
        inv_F[i] %= MOD;
    }
    function<int64_t(int, int)> C = [&](int n, int k) {
        return F[n] * inv_F[k] % MOD * inv_F[n - k] % MOD;
    };
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    a[n] = {h, w};
    sort(a.begin(), a.end());
    vector<int64_t> ans(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        int x = a[i].first;
        int y = a[i].second;
        ans[i] = C(x + y - 2, x - 1);
        for (int j = 0; j < i; ++j) {
            if (a[j].first <= x && a[j].second <= y) {
                int nx = a[j].first;
                int ny = a[j].second;
                ans[i] -= ans[j] * C(x - nx + y - ny, x - nx) % MOD;
                ans[i] += MOD;
                ans[i] %= MOD;
            }
        }
    }
    cout << ans[n];
}
