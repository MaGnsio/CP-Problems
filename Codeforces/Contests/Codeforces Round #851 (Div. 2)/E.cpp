/**
 *    author:  MaGnsi0
 *    created: 11.02.2023 20:57:12
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
    int n;
    cin >> n;
    vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    set<int64_t> p(a.begin(), a.end());
    map<int64_t, int> mp;
    for (auto& x : p) {
        mp[x] = mp.size();
    }
    int m = (int)mp.size();
    segment_tree<int64_t> b(m, -OO, [](int64_t x, int64_t y) { return max(x, y); });
    vector<int64_t> dp(n + 1, -OO);
    dp[0] = 0;
    b.update(mp[0], 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i - 1], b.query(0, mp[a[i]] + 1) + i);
        if (b.query(mp[a[i]], mp[a[i]] + 1) < dp[i] - i) {
            b.update(mp[a[i]], dp[i] - i);
        }
    }
    cout << dp[n];
}
