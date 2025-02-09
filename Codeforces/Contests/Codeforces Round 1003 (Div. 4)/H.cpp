/**
 *    author:  MaGnsi0
 *    created: 10.02.2025 00:33:57
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5, MOD = 998244353;

struct Node {
    int64_t m, p[2], s[2], ans[2];
    Node() { m = p[0] = p[1] = s[0] = s[1] = ans[0] = ans[1] = 0; }
    Node(int t) { m = p[t] = s[t] = 1; p[t ^ 1] = s[t ^ 1] = ans[t] = ans[t ^ 1] = 0; }
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
    vector<int64_t> P2(N, 1);
    for (int i = 1; i < N; ++i) {
        P2[i] = P2[i - 1] * 2 % MOD;
    }
    function<Node(Node, Node)> F = [&](Node L, Node R) {
        if (L.m == 0) { return R; }
        if (R.m == 0) { return L; }
        Node P;
        P.m = L.m + R.m;
        for (int t = 0; t < 2; ++t) {
            P.p[t] = (L.p[t] + P2[L.m] * R.p[t]) % MOD;
            P.s[t] = (P2[R.m] * L.s[t] + R.s[t]) % MOD;
            P.ans[t] = (P2[R.m] * L.ans[t] % MOD + P2[L.m] * R.ans[t] % MOD + R.s[t] * L.p[t ^ 1] % MOD) % MOD;
        }
        return P;
    };
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int)s.size();
        segment_tree<Node> S(n, Node(), F);
        function<int64_t()> get_ans = [&]() {
            Node root = S.query(0, n);
            int64_t ans = (root.ans[0] + root.ans[1] + P2[n] - 1) % MOD;
            return ans;
        };
        for (int i = 0; i < n; ++i) {
            S.update(i, Node(s[i] - '0'));
        }
        int Q; cin >> Q;
        while (Q--) {
            int j; cin >> j; j--;
            s[j] = (s[j] == '1' ? '0' : '1');
            S.update(j, Node(s[j] - '0'));
            cout << get_ans() << (Q ? " " : "\n");
        }
    }
}
