/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 15:16:41
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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> ans(n, 0);
    sparse_table<int> b(a, [](int x, int y) { return max(x, y); });
    for (int i = 1; i < n; ++i) {
        int low = 0, high = i - 1, j = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (b.get(mid, i - 1) > a[i]) {
                j = mid; low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans[j]++, ans[i]--;
    }
    for (int i = 1; i < n; ++i) {
        ans[i] += ans[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
