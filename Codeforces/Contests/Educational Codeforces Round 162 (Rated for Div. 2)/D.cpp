/**
 *    author:  MaGnsi0
 *    created: 28.02.2024 21:10:00
**/
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> b(n + 1);
        for (int i = 1; i <= n; ++i) {
            b[i] = b[i - 1] + a[i];
        }
        sparse_table<int64_t> maxa(a, [&](int64_t x, int64_t y) { return max(x, y); });
        sparse_table<int64_t> mina(a, [&](int64_t x, int64_t y) { return min(x, y); });
        vector<int> ans(n + 1, n);
        for (int i = 1; i <= n; ++i) {
            if (i != n && a[i + 1] > a[i]) {
                ans[i] = 1;
                continue;
            }
            if (i != 1 && a[i - 1] > a[i]) {
                ans[i] = 1;
                continue;
            }
            {
                int low = i + 1, high = n, time = -1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    bool can_eat = (maxa.get(i + 1, mid) != mina.get(i + 1, mid)) || (mid == i + 1);
                    int64_t sum = b[mid] - b[i];
                    if (can_eat && sum > a[i]) {
                        time = mid - i;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                if (time != -1) {
                    ans[i] = min(ans[i], time);
                }
            }
            {
                int low = 1, high = i - 1, time = -1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    bool can_eat = (maxa.get(mid, i - 1) != mina.get(mid, i - 1)) || (mid == i - 1);
                    int64_t sum = b[i - 1] - b[mid - 1];
                    if (can_eat && sum > a[i]) {
                        time = i - mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (time != -1) {
                    ans[i] = min(ans[i], time);
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << (ans[i] == n ? -1 : ans[i]) << " ";
        }
        cout << "\n";
    }
}
