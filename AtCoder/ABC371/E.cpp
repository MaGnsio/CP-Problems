/**
 *    author:  MaGnsi0
 *    created: 14.09.2024 15:29:20
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
        cin >> a[i]; a[i]--;
    }
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        reverse(pos[i].begin(), pos[i].end());
    }
    segment_tree<int64_t> b(n, 0, [](int64_t x, int64_t y) { return x + y; });
    for (int i = 0; i < n; ++i) {
        if (pos[i].empty()) { continue; }
        b.update(pos[i].back(), n - pos[i].back());
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += b.query(0, n);
        b.update(pos[a[i]].back(), 0);
        pos[a[i]].pop_back();
        if (pos[a[i]].empty()) { continue; }
        b.update(pos[a[i]].back(), n - pos[a[i]].back());
    }
    cout << ans;
}
