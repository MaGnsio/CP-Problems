/**
 *    author:  MaGnsi0
 *    created: 31.01.2024 21:49:25
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segment_tree<int> b(n, 0, [](int x, int y) { return max(x, y); });
    for (int i = 0; i < n; ++i) {
        b.update(i, a[i]);
    }
    map<int, set<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]].insert(i);
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = mp[a[i]].upper_bound(i);
        if (it == mp[a[i]].end()) { continue; }
        int j = *it;
        if (b.query(i + 1, j) < a[i]) {
            ans += j - i - 1;
        }
    }
    cout << ans;
}
