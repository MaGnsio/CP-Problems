/**
 *    author:  MaGnsi0
 *    created: 26.10.2024 08:13:08
**/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

template <typename T, class F = function<T(const T&, const T&)>>
struct sparse_table {
    int n;
    vector<vector<T>> mat;
    F func;
    sparse_table(const vector<T>& a, const F& f) : func(f) {
        n = (int)a.size();
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; ++j) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); ++i) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T get(int from, int to) {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    int64_t a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + (i ? b[i - 1] : 0);
    }
    vector<int> R(n, -1);
    while (Q--) {
        int x; cin >> x;
        if (x == 0) {
            cout << 0 << "\n";
            continue;
        }
        int64_t res = 0;
        for (int i = 0; i < n; ++i) { R[i] = -1; }
        for (int i = 0, j = n - 1; i < n; ++i) {
            if (a[i] > x) { break; }
            while (j > i && a[i] + a[j] > x) { j--; }
            R[i] = max(i, j) + i;
        }
        sparse_table<int> c(R, [&](int x, int y) { return min(x, y); });
        for (int i = 0; i < n; ++i) {
            if (R[i] == -1) { break; }
            int k = c.get(i, R[i] - i);
            if (k == -1) { break; }
            k = k - i;
            if (k != n - 1 && (k - i + 1) % 2 == 0 && a[k + 1] <= x) { k++; }
            res += b[k] - (i ? b[i - 1] : 0) - (k - i + 1) * a[i];
        }
        cout << res << "\n";
    }
}
