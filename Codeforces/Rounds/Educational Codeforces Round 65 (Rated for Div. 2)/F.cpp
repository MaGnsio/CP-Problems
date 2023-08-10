/**
 *    author:  MaGnsi0
 *    created: 06.08.2023 14:55:56
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

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
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> S(a.begin(), a.end());
    map<int, int> mp;
    for (int64_t x : S) {
        mp[x] = (int)mp.size();
    }
    int64_t ans = 0;
    for (int64_t i = 0; i < n; ++i) {
        ans += (i + 1) * (n - i) % MOD * a[i] % MOD;
        ans %= MOD;
    }
    for (int _ = 0; _ < 2; ++_) {
        segment_tree<int64_t> b(n, 0, [&](int64_t x, int64_t y) { return (x + y) % MOD; });
        for (int64_t i = 0; i < n; ++i) {
            ans += b.query(0, mp[a[i]] + 1) * (n - i) % MOD * a[i] % MOD;
            ans %= MOD;
            b.update(mp[a[i]], i + 1);
        }
        reverse(a.begin(), a.end());
    }
    cout << ans;
}
