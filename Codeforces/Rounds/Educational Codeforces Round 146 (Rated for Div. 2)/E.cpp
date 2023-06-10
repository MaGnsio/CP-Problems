/**
 *    author:  MaGnsi0
 *    created: 06.04.2023 16:36:03
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e18;
const array<array<int64_t, 2>, 2> O = {{{OO, OO}, {OO, OO}}};

array<array<int64_t, 2>, 2> F(array<array<int64_t, 2>, 2> x, array<array<int64_t, 2>, 2> y) {
    if (x == O) { return y; }
    if (y == O) { return x; }
    array<array<int64_t, 2>, 2> z = O;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if (k == 0 && l == 0) { continue; }
                    z[i][j] = min(z[i][j], x[i][k] + y[l][j]);
                }
            }
        }
    }
    return z;
}

array<array<int64_t, 2>, 2> G(int64_t x) {
    array<array<int64_t, 2>, 2> ans = O;
    ans[0][0] = 0, ans[1][1] = x;
    return ans;
}

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
    vector<int64_t> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }
    segment_tree<array<array<int64_t, 2>, 2>> b(n - 1, O, F);
    for (int i = 0; i < n - 1; ++i) {
        b.update(i, G(a[i]));
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int k;
        int64_t x;
        cin >> k >> x;
        b.update(k - 1, G(x));
        cout << 2 * b.query(0, n - 1)[1][1] << "\n";
    }
}
