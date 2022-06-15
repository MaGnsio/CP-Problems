/**
 *    author:  MaGnsi0
 *    created: 08.06.2022 01:56:47
**/
#include <bits/stdc++.h>

using namespace std;

struct matrix {
    int64_t a11, a12, a21, a22;
    matrix(int64_t a11, int64_t a12, int64_t a21, int64_t a22) : a11(a11), a12(a12), a21(a21), a22(a22) {}
};

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
    int r, n, m;
    cin >> r >> n >> m;
    function<matrix(matrix, matrix)> f = [&](matrix x, matrix y) {
        matrix z(0, 0, 0, 0);
        z.a11 = (x.a11 * y.a11 + x.a12 * y.a21) % r;
        z.a12 = (x.a11 * y.a12 + x.a12 * y.a22) % r;
        z.a21 = (x.a21 * y.a11 + x.a22 * y.a21) % r;
        z.a22 = (x.a21 * y.a12 + x.a22 * y.a22) % r;
        return z;
    };
    segment_tree<matrix> a(n, matrix(1, 0, 0, 1), f);
    for (int i = 0; i < n; ++i) {
        int a11, a12, a21, a22;
        cin >> a11 >> a12 >> a21 >> a22;
        a.update(i, matrix(a11, a12, a21, a22));
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        matrix ans = a.query(l - 1, r);
        cout << ans.a11 << " " << ans.a12 << "\n";
        cout << ans.a21 << " " << ans.a22 << "\n\n";
    }
}
