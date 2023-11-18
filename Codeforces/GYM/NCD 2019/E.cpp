/**
 *    author:  MaGnsi0
 *    created: 16.10.2023 00:00:51
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e5 + 5;
const int64_t P[2] = {31, 53};
const int64_t MOD[2] = {int64_t(1e9 + 7), int64_t(1e9 + 9)};

struct node {
    int s;
    array<int64_t, 2> hash;
    node() {}
    node(int s_) : s(s_) {}
    node(int s_, array<int64_t, 2> hash_) : s(s_), hash(hash_) {}
};

const node O(-1);

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
    vector<vector<int64_t>> pow(2, vector<int64_t>(N, 1));
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < N; ++j) {
            pow[i][j] = pow[i][j - 1] * P[i] % MOD[i];
        }
    }
    function<array<int64_t, 2>(char)> H = [&](char c) {
        array<int64_t, 2> res;
        for (int i = 0; i < 2; ++i) {
            res[i] = pow[i][0] * P[i] * (c - 'a') % MOD[i];
        }
        return res;
    };
    function<node(node, node)> F = [&](node L, node R) {
        if (L.s == -1) { return R; }
        if (R.s == -1) { return L; }
        node res;
        res.s = L.s + R.s;
        for (int i = 0; i < 2; ++i) {
            res.hash[i] = (L.hash[i] + pow[i][L.s] * R.hash[i] % MOD[i]) % MOD[i];
        }
        return res;
    };
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        string s; cin >> s;
        segment_tree<node> b(n, O, F);
        segment_tree<node> c(n, O, F);
        for (int i = 0; i < n; ++i) {
            b.update(i, node(1, H(s[i])));
            c.update(n - i - 1, node(1, H(s[i])));
        }
        while (Q--) {
            int t; cin >> t;
            if (t == 1) {
                int j; cin >> j; j--;
                char x; cin >> x;
                b.update(j, node(1, H(x)));
                c.update(n - j - 1, node(1, H(x)));
            } else {
                int low; cin >> low; low--;
                int high; cin >> high; high--;
                array<int64_t, 2> x = b.query(low, high + 1).hash;
                array<int64_t, 2> y = c.query(n - high - 1, n - low).hash;
                cout << (x[0] == y[0] && x[1] == y[1] ? "Adnan Wins" : "ARCNCD!") << "\n";
            }
        }
    }
}
