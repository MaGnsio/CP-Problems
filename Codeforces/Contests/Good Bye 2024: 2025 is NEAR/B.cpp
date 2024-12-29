/**
 *    author:  MaGnsi0
 *    created: 29.12.2024 23:18:07
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
        }
        segment_tree<int> b(2 * n + 1, n + 1, [](int x, int y) { return min(x, y); });
        for (int i = 0; i <= 2 * n; ++i) {
            b.update(i, 0);
        }
        for (int i = 0; i < n; ++i) {
            if (l[i] == r[i]) {
                b.update(l[i], b.query(l[i], r[i] + 1) + 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (l[i] == r[i]) {
                b.update(l[i], b.query(l[i], r[i] + 1) - 1);
            }
            cout << (b.query(l[i], r[i] + 1) == 0);
            if (l[i] == r[i]) {
                b.update(l[i], b.query(l[i], r[i] + 1) + 1);
            }
        }
        cout << "\n";
    }
}
