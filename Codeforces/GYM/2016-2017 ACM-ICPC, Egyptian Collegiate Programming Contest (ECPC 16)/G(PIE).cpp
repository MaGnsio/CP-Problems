/**
 *    author:  MaGnsi0
 *    created: 28.05.2022 14:14:52
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e3 + 3, MOD = 1e9 + 7;

template <typename T>
T power(T b, T p, T m) {
    T res = 1;
    while (p) {
        if (p & 1) {
            res = ((res % m) * (b % m)) % m;
        }
        b = ((b % m) * (b % m)) % m;
        p >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("galactic.in", "r", stdin);
    vector<vector<int64_t>> C(N, vector<int64_t>(N));
    C[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= MOD;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        if (k > n) {
            cout << 0 << "\n";
            continue;
        }
        int64_t ans = power(k, n, MOD);
        for (int i = 1; i <= k; ++i) {
            ans += (i & 1 ? -1 : 1) * C[k][i] * power(k - i, n, MOD);
            ans += MOD;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
