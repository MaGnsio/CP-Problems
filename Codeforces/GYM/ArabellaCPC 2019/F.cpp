/**
 *    author:  MaGnsi0
 *    created: 23.10.2023 03:39:06
**/
#include <bits/stdc++.h>

using namespace std;

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
    int n; cin >> n;
    int p; cin >> p; p--;
    vector<int> a(n - 1), b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i]; b[i]--;
    }
    segment_tree<int> c(n, 0, [&](int x, int y) { return x + y; });
    for (int i = 0; i < n - 1; ++i) {
        c.update(b[i], 1);
        b[i] = b[i] - c.query(0, b[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n, -1));
    function<int(int, int)> solve = [&](int x, int y) {
        if (x == 1) { return 1; }
        if (dp[x][y] != -1) { return dp[x][y]; }
        dp[x][y] = 0;
        int move = a[n - x] % x;
        int pos_cw = (y + move) % x;
        int pos_ccw = (y - move + x) % x;
        if (pos_cw != b[n - x]) {
            dp[x][y] = max(dp[x][y], solve(x - 1, pos_cw - (b[n - x] < pos_cw)));
        }
        if (pos_ccw != b[n - x]) {
            dp[x][y] = max(dp[x][y], solve(x - 1, pos_ccw - (b[n - x] < pos_ccw)));
        }
        return dp[x][y];
    };
    cout << (solve(n, p) ? "Yes" : "No");
}
