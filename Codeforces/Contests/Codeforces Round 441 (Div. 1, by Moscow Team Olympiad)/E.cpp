/**
 *    author:  MaGnsi0
 *    created: 06.08.2024 15:05:23
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
    int n; cin >> n; n += 2;
    vector<int> a(n);
    cin >> a[0] >> a[1];
    for (int i = 2; i < n; ++i) {
        cin >> a[i];
    }
    sparse_table<int> a_max(a, [](int x, int y) { return max(x, y); });
    sparse_table<int> a_min(a, [](int x, int y) { return min(x, y); });
    function<bool(int)> solve = [&](int d) {
        segment_tree<int> dp(n + 1, 0, [](int x, int y) { return max(x, y); });
        dp.update(n, 1);
        for (int i = n - 1; i; --i) {
            int b = a[i - 1];
            int dl = b - d, dr = b + d;
            int j = n;
            {
                int low = i, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a_max.get(i, mid) > dr) {
                        j = min(j, mid);
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            {
                int low = i, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a_min.get(i, mid) < dl) {
                        j = min(j, mid);
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            dp.update(i, dp.query(i, j + 1));
        }
        return dp.query(1, 2) > 0;
    };
    function<bool(int)> F = [&](int d) {
        if (solve(d)) { return true; }
        swap(a[0], a[1]);
        return solve(d);
    };
    int low = abs(a[0] - a[1]), high = 1e9, ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (F(mid)) {
            ans = mid, high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
}
