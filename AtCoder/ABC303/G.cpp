/**
 *    author:  MaGnsi0
 *    created: 10.06.2023 00:32:10
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e16;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] = x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    vector<int64_t> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    vector<int64_t> p(N + 1);
    for (int i = 0; i < N; ++i) {
        p[i + 1] = p[i] + x[i];
    }
    vector<vector<int64_t>> dp(N, vector<int64_t>(N, -OO));
    vector<segment_tree<int64_t>> b(N, segment_tree<int64_t>(N, OO, [](int64_t x, int64_t y) { return min(x, y); }));
    for (int m = 1; m <= N; ++m) {
        for (int i = 0; i + m <= N; ++i) {
            int j = i + m - 1;
            if (m == 1) {
                dp[i][j] = max(dp[i][j], x[i]);
            } else {
                dp[i][j] = max({dp[i][j], x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]});
            }
            if (m <= B) {
                dp[i][j] = max(dp[i][j], p[j + 1] - p[i] - A);
            } else {
                dp[i][j] = max(dp[i][j], p[j + 1] - p[i] - A - b[m - B - 1].query(i, j - m + B + 2));
            }
            if (m <= D) {
                dp[i][j] = max(dp[i][j], p[j + 1] - p[i] - C);
            } else {
                dp[i][j] = max(dp[i][j], p[j + 1] - p[i] - C - b[m - D - 1].query(i, j - m + D + 2));
            }
            b[m - 1].update(i, dp[i][j] + p[j + 1] - p[i]);
        }
    }
    cout << dp[0][N - 1];
}
