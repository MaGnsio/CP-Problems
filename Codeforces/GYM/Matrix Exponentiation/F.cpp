/**
 *    author:  MaGnsi0
 *    created: 19.08.2022 07:40:50
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 100, OO = INT64_MAX;

template <typename T, int N>
struct matrix {
    array<array<T, N>, N> A{};
    matrix operator*(const matrix& b) const {
        matrix c;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                c.A[i][j] = OO;
                for (int k = 0; k < N; ++k) {
                    if (A[i][k] == OO || b.A[k][j] == OO) {
                        continue;
                    }
                    c.A[i][j] = min(c.A[i][j], A[i][k] + b.A[k][j]);
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

using M = matrix<int64_t, N>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    M adj;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            adj.A[i][j] = OO;
        }
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.A[u - 1][v - 1] = w;
    }
    adj = power<M, int64_t>(adj, k);
    int64_t ans = OO;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = min(ans, adj.A[i][j]);
        }
    }
    if (ans == OO) {
        cout << "IMPOSSIBLE";
    } else {
        cout << ans;
    }
}
