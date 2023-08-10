/**
 *    author:  MaGnsi0
 *    created: 14.07.2023 15:43:04
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
        for (S[j += N] += x; j /= 2;) {
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    map<int, int> colors;
    for (int i = 0; i < n; ++i) {
        colors[b[i]]++;
    }
    map<int, int> L, R, I, E;
    for (auto [color, x] : colors) {
        L[color] = (R.empty() ? 0 : R.rbegin() -> second + 1);
        R[color] = L[color] + x - 1;
        I[color] = L[color];
        E[color] = E.size();
    }
    vector<int64_t> c(n), d(n);
    for (int i = 0; i < n; ++i) {
        c[I[b[i]]] = a[i];
        d[I[b[i]]] = b[i];
        I[b[i]]++;
    }
    for (int i = 1; i < n; ++i) {
        c[i] += c[i - 1];
    }
    int Q, m = (int)E.size() + 1;
    cin >> Q;
    segment_tree<int64_t> S(m, 0, [](int64_t x, int64_t y) { return x + y; });
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int64_t color, x;
            cin >> color >> x;
            S.update(0, x);
            S.update(m - 1, -x);
            if (E.count(color)) {
                S.update(E[color], -x);
                S.update(E[color] + 1, x);
            }
        } else {
            int64_t color, y;
            cin >> color >> y;
            int low = L[color], high = R[color], ans = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                int64_t sum = c[mid] - (L[color] ? c[L[color] - 1] : 0) + (mid - L[color] + 1) * S.query(0, E[color] + 1);
                if (sum <= y) {
                    ans = mid - L[color] + 1;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            cout << ans << "\n";
        }
    }
}
