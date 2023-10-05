/**
 *    author:  MaGnsi0
 *    created: 11.08.2022 20:55:54
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segment_tree<int> s(n, INT_MAX, [](int x, int y) { return min(x, y); });
    for (int i = 0; i < n; ++i) {
        s.update(i, a[i]);
    }
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int l = 0, r = i, L = 0, R = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (s.query(m, i + 1) == a[i]) {
                L = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        l = i, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (s.query(i, m + 1) == a[i]) {
                R = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        ans[R - L + 1] = max(ans[R - L + 1], a[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
}
