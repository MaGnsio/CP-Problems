/**
 *    author:  MaGnsi0
 *    created: 03.12.2024 19:53:55
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t K = 5, OO = 1e16;

struct Node {
    array<array<int64_t, K>, K> dp;
    Node() {
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                dp[i][j] = -OO;
            }
        }
    }
    Node(int64_t x, int64_t y) {
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                dp[i][j] = -OO;
            }
        }
        dp[0][0] = 0, dp[0][1] = x + y, dp[0][2] = x + 2 * y;
        dp[1][1] = x, dp[1][2] = x + y;
        dp[2][2] = 0, dp[2][3] = x + y, dp[2][4] = x + 2 * y;
        dp[3][3] = x, dp[3][4] = x + y;
        dp[4][4] = 0;
    }
    static Node merge(Node L, Node R) {
        if (R.dp == Node().dp) { return L; }
        if (L.dp == Node().dp) { return R; }
        Node res;
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                for (int k = 0; k < K; ++k) {
                    res.dp[i][j] = max(res.dp[i][j], L.dp[i][k] + R.dp[k][j]);
                }
            }
        }
        return res;
    }
};

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
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    segment_tree<Node> S(n, Node(), Node::merge);
    for (int i = 0; i < n; ++i) {
        S.update(i, Node(a[i], b[i]));
    }
    int Q; cin >> Q;
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int j; cin >> j; j--;
            int64_t x; cin >> x; a[j] = x;
            S.update(j, Node(a[j], b[j]));
        } else if (t == 2) {
            int j; cin >> j; j--;
            int64_t x; cin >> x; b[j] = x;
            S.update(j, Node(a[j], b[j]));
        } else {
            int l; cin >> l; l--;
            int r; cin >> r; r--;
            int64_t ans = S.query(l, r + 1).dp[0][4];
            cout << ans << "\n";
        }
    }
}
