/**
 *    author:  MaGnsi0
 *    created: 24.11.2023 17:05:12
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
    int n; cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segment_tree<int64_t> b(n, -OO, [](int64_t x, int64_t y) { return max(x, y); });
    segment_tree<int64_t> c(n, -OO, [](int64_t x, int64_t y) { return max(x, y); });
    for (int i = 0; i < n; ++i) {
        b.update(i, a[i] + i);
        c.update(i, a[i] - i);
    }
    int64_t ans = OO;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, max({c.query(0, i) + n - 1, a[i], b.query(i + 1, n)}));
    }
    cout << ans;
}
