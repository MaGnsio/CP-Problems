/**
 *    author:  MaGnsi0
 *    created: 03.11.2024 16:36:29
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 200, MOD = 1e9 + 7;
 
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
    int n; cin >> n;
    int m; cin >> m;
    int Q; cin >> Q;
    using M = matrix<int64_t, N, MOD>;
    M adj;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj.A[u - 1][v - 1] = 1;
        adj.A[v - 1][u - 1] = 1;
    }
    vector<M> S(24);
    S[0] = adj;
    for (int i = 1; i < 24; ++i) {
        S[i] = S[i - 1] * S[i - 1];
    }
    while (Q--) {
        int v; cin >> v; v--;
        int k; cin >> k;
        vector<int64_t> dp(n); dp[v] = 1;
        for (int b = 0; b < 24; ++b) {
            if (k >> b & 1) {
                vector<int64_t> dp_(n);
                for (int j = 0; j < N; ++j) {
                    for (int k = 0; k < N; ++k) {
                        dp_[j] += dp[k] * S[b].A[k][j];
                        dp_[j] %= MOD;
                    }
                }
                swap(dp_, dp);
            }
        }
        int64_t ans = 0;
        for (int u = 0; u < n; ++u) {
            ans += dp[u];
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
