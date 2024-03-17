/**
 *    author:  MaGnsi0
 *    created: 03.12.2023 14:46:24
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

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
    vector<int64_t> a(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i]; a[i]++;
    }
    vector<int64_t> dp(n);
    segment_tree<int64_t> sum(n, 0, [&](int64_t x, int64_t y) { return (x + y) % MOD; });
    for (int i = n - 2; i >= 0; --i) {
        int64_t x = power(a[i], MOD - 2);
        dp[i] = power((1 - x + MOD) % MOD, MOD - 2) * (x * sum.query(i + 1, i + a[i]) % MOD + 1) % MOD;
        sum.update(i, dp[i]);
    }
    cout << dp[0];
}
