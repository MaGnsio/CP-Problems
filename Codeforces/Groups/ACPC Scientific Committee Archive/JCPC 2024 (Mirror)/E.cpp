/**
 *    author:  MaGnsi0
 *    created: 11.11.2024 19:31:25
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T, class F = function<T(const T&, const T&)>>
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            a[i] = b[i] - a[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
        }
        vector<int64_t> c(n);
        for (int i = 0; i + k - 1 < n; ++i) {
            c[i] = b[i + k - 1] - (i ? b[i - 1] : 0);
        }
        sparse_table<int64_t> a_min(a, [](int64_t x, int64_t y) { return min(x, y); });
        sparse_table<int64_t> a_max(a, [](int64_t x, int64_t y) { return max(x, y); });
        sparse_table<int64_t> c_max(c, [](int64_t x, int64_t y) { return max(x, y); });
        int64_t ans = INT64_MIN;
        for (int i = 0; i + k - 1 < n; ++i) {
            int L = i, R = i + k - 1;
            {
                int low = 0, high = i;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (c_max.get(mid, i) == c[i]) {
                        L = mid; high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            {
                int low = i, high = n - k;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (c_max.get(i, mid) == c[i]) {
                        R = mid + k - 1, low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            int64_t x = a_max.get(i + k - 1, R);
            int64_t y = i ? a_min.get((L ? L - 1 : L), i - 1) : 0;
            if (L == 0) { y = min(y, int64_t(0)); }
            int64_t z = c[i];
            ans = max(ans, x - y - z);
        }
        cout << ans << "\n";
    }
}
