/**
 *    author:  MaGnsi0
 *    created: 03.01.2023 17:31:11
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
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        segment_tree<int64_t> b(n, 0, [](int64_t x, int64_t y) { return x + y; });
        for (int i = 0; i < n; ++i) {
            b.update(i, a[i]);
        }
        int ans = 0;
        set<pair<int64_t, int>> s;
        s.emplace(a[m - 1], m - 1);
        for (int i = m - 2; i >= 0; --i) {
            while (b.query(0, i + 1) < b.query(0, m)) {
                auto it = s.rbegin();
                int j = it -> second;
                a[j] *= -1;
                s.erase(*it);
                b.update(j, a[j]);
                ans++;
            }
            s.emplace(a[i], i);
        }
        s.clear();
        for (int i = m; i < n; ++i) {
            s.emplace(a[i], i);
            while (b.query(0, i + 1) < b.query(0, m)) {
                auto it = s.begin();
                int j = it -> second;
                a[j] *= -1;
                s.erase(it);
                b.update(j, a[j]);
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
