/**
 *    author:  MaGnsi0
 *    created: 25.07.2024 17:30:55
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 9;

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

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> P2(n + 1, 1), P2_(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        P2[i] = P2[i - 1] * 2 % MOD;
        P2_[i] = power(P2[i], MOD - 2);
    }
    segment_tree<int64_t> b(n, 0, [&](int64_t x, int64_t y) { return (x + y) % MOD; });
    for (int i = 0; i < n; ++i) {
        b.update(i, a[i] * P2[n - i - 1] % MOD);
    }
    set<int> bad;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 1) { bad.insert(i); }
    }
    int Q; cin >> Q;
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int j; cin >> j; j--;
            int64_t x; cin >> x;
            a[j] = (a[j] ^ x) & 1;
            b.update(j, a[j] * P2[n - j - 1] % MOD);
            bad.erase(j);
        } else {
            int l; cin >> l; l--;
            int r; cin >> r; r--;
            auto it = bad.lower_bound(l);
            if (it != bad.end() && *it <= r) {
                cout << "Impossible\n";
            } else {
                cout << b.query(l, r + 1) * P2_[n - r - 1] % MOD << "\n";
            }
        }
    }
}
