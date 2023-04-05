/**
 *    author:  MaGnsi0
 *    created: 09.02.2023 13:23:16
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e15;

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
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int64_t> a(n + 2);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<bool> must(n + 2, false);
        must[0] = must[n + 1] = true;
        for (int i = 1; i <= n; ++i) {
            char x;
            cin >> x;
            if (x == '1') { must[i] = true; }
        }
        vector<vector<int>> next_must(2, vector<int>(n + 2, -1));
        for (int i = n, j = n + 1; i >= 0; --i) {
            next_must[0][i] = j;
            if (must[i]) { j = i; }
        }
        for (int i = 1, j = 0; i <= n + 1; ++i) {
            next_must[1][i] = j;
            if (must[i]) { j = i; }
        }
        vector<vector<int64_t>> dp(2, vector<int64_t>(n + 2, OO));
        vector<segment_tree<int64_t>> b(2, segment_tree<int64_t>(n + 2, OO, [](int64_t x, int64_t y) { return min(x, y); }));
        dp[0][n + 1] = 0;
        b[0].update(n + 1, dp[0][n + 1]);
        for (int i = n; i >= 0; --i) {
            int L = i + 1, R = min(next_must[0][i], i + k);
            dp[0][i] = b[0].query(L, R + 1) + a[i];
            b[0].update(i, dp[0][i]);
        }
        dp[1][0] = 0;
        b[1].update(0, dp[1][0]);
        for (int i = 1; i <= n + 1; ++i) {
            int L = max(next_must[1][i], i - k), R = i - 1;
            dp[1][i] = b[1].query(L, R + 1) + a[i];
            b[1].update(i, dp[1][i]);
        }
        int Q;
        cin >> Q;
        while (Q--) {
            int j;
            int64_t x;
            cin >> j >> x;
            int L1 = max(next_must[1][j], j - k);
            int R1 = j - 1;
            int L2 = j + 1;
            int R2 = min(next_must[0][j], j + k);
            int64_t ans = b[1].query(L1, R1 + 1) + x + b[0].query(L2, R2 + 1);
            if (!must[j]) {
                for (int i = L1; i <= R1; ++i) {
                    int x = k - (j - i);
                    if (x <= 0) {
                        continue;
                    }
                    int L = j + 1, R = min(j + x, next_must[0][j]);
                    ans = min(ans, dp[1][i] + b[0].query(L, R + 1));
                }
            }
            cout << ans << "\n";
        }
    }
}
