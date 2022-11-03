/**
 *    author:  MaGnsi0
 *    created: 15.08.2022 05:29:52
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 100, MOD = 1e9 + 7;

template <typename T, int N, T MOD>
struct matrix {
    array<array<T, N>, N> A{};
    matrix operator*(const matrix& b) const {
        matrix c;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    c.A[i][j] += A[i][k] * b.A[k][j];
                    c.A[i][j] %= MOD;
                }
            }
        }
        return c;
    }
};

template <typename P, typename T>
P power(P b, T p) {
    P res;
    for (int i = 0; i < (int)res.A.size(); ++i) {
        res.A[i][i] = 1;
    }
    while (p) {
        if (p & 1) {
            res = res * b;
        }
        b = b * b;
        p >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    using M = matrix<int64_t, N, MOD>;
    M adj;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj.A[u - 1][v - 1] = 1;
    }
    adj = power<M, int64_t>(adj, k);
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += adj.A[i][j];
            ans %= MOD;
        }
    }
    cout << ans;
}
