/**
 *    author:  MaGnsi0
 *    created: 27.11.2024 20:46:15
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 13, MOD = 1e9 + 7;

struct Node {
    array<int64_t, N> dp;
    Node() { dp.fill(0); }
    Node(int x) {
        assert(1 <= x && x <= 13);
        dp.fill(0); dp[x % 13] = 1;
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

Node F(Node L, Node R) {
    Node res;
    for (int i = 1; i < N; ++i) {
        res.dp[i] += L.dp[i]; res.dp[i] %= MOD;
        res.dp[i] += R.dp[i]; res.dp[i] %= MOD;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            int k = (i * j) % 13;
            res.dp[k] += L.dp[i] * R.dp[j] % MOD; res.dp[k] %= MOD;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    segment_tree<Node> b(n, Node(), F);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b.update(i, Node(x));
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int j; cin >> j; j--;
            int x; cin >> x;
            b.update(j, Node(x));
        } else {
            int l; cin >> l; l--;
            int r; cin >> r; r--;
            int64_t ans = b.query(l, r + 1).dp[5];
            cout << ans << "\n";
        }
    }
}
