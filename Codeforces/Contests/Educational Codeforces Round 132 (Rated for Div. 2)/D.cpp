/**
 *    author:  MaGnsi0
 *    created: 21.07.2022 16:34:44
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
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    segment_tree<int64_t> st(m, 0, [](int64_t x, int64_t y) { return max(x, y); });
    for (int i = 0; i < m; ++i) {
        st.update(i, a[i]);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int64_t xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        if (abs(ys - yf) % k || abs(xs - xf) % k) {
            cout << "NO\n";
        } else {
            int64_t highest = xs + k * ((n - xs) / k);
            if (ys > yf) {
                swap(ys, yf);
            }
            if (st.query(ys - 1, yf) >= highest) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}
