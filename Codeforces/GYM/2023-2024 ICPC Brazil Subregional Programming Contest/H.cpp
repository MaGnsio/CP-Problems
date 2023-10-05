/**
 *    author:  MaGnsi0
 *    created: 13.09.2023 19:07:33
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
        if (L == R) { return E; }
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
    int n, S;
    cin >> n >> S;
    vector<tuple<int, int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        a[i] = {l, r, c};
    }
    sort(a.begin(), a.end());
    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(get<0>(a[i]));
        s.insert(get<1>(a[i]));
    }
    map<int, int> mp;
    for (int x : s) {
        mp[x] = (int)mp.size();
    }
    int m = (int)mp.size();
    segment_tree<int64_t> b(m, 0, [](int64_t x, int64_t y) { return max(x, y); });
    segment_tree<int64_t> c(m, 0, [](int64_t x, int64_t y) { return max(x, y); });
    vector<int64_t> dp(n);
    for (int i = n - 1; i >= 0; --i) {
        int64_t L = get<0>(a[i]);
        int64_t R = get<1>(a[i]);
        int64_t C = get<2>(a[i]);
        int j = mp[L], k = mp[R];
        int64_t x = b.query(j, k + 1) - L * S - C;
        int64_t y = c.query(k + 1, m) + (R - L + 1) * S - C;
        dp[i] = max(x, y);
        b.update(j, max(dp[i] + L * S, b.query(j, j + 1)));
        c.update(j, max(dp[i], c.query(j, j + 1)));
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
