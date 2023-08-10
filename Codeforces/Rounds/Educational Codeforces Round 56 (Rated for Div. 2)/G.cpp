/**
 *    author:  MaGnsi0
 *    created: 03.08.2023 16:12:12
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e8;

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
    int n, k;
    cin >> n >> k;
    int m = (1 << k);
    vector<segment_tree<int>> a(m, segment_tree<int>(n, -OO, [](int x, int y) { return max(x, y); }));
    vector<segment_tree<int>> b(m, segment_tree<int>(n, OO, [](int x, int y) { return min(x, y); }));
    for (int i = 0; i < n; ++i) {
        vector<int> p(k);
        for (int j = 0; j < k; ++j) {
            cin >> p[j];
        }
        for (int mask = 0; mask < m; ++mask) {
            int val = 0;
            for (int j = 0; j < k; ++j) {
                val += (mask >> j & 1 ? 1 : -1) * p[j];
            }
            a[mask].update(i, val);
            b[mask].update(i, val);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; cin >> i;
            vector<int> p(k);
            for (int j = 0; j < k; ++j) {
                cin >> p[j];
            }
            for (int mask = 0; mask < m; ++mask) {
                int val = 0;
                for (int j = 0; j < k; ++j) {
                    val += (mask >> j & 1 ? 1 : -1) * p[j];
                }
                a[mask].update(i - 1, val);
                b[mask].update(i - 1, val);
            }
        } else {
            int low, high;
            cin >> low >> high;
            int ans = -OO;
            for (int mask = 0; mask < m; ++mask) {
                ans = max(ans, a[mask].query(low - 1, high) - b[mask].query(low - 1, high));
            }
            cout << ans << "\n";
        }
    }
}
