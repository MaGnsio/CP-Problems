/**
 *    author:  MaGnsi0
 *    created: 16.02.2025 18:05:18
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
        int k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sparse_table<int> mina(a, [](int x, int y) { return min(x, y); });
        sparse_table<int> maxa(a, [](int x, int y) { return max(x, y); });
        function<pair<int, int>(int, int)> F = [&](int i, int x) {
            int L = -1, R = -1;
            {
                int low = 0, high = i;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (mina.get(mid, i) == x) {
                        R = mid; low = mid + 1;
                    } else if (mina.get(mid, i) > x) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            if (R == -1) { return make_pair(-1, -1); }
            {
                int low = 0, high = R;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (mina.get(mid, R) == x) {
                        L = mid; high = mid - 1; 
                    } else if (mina.get(mid, R) > x) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            return make_pair(L, R);
        };
        function<pair<int, int>(int, int)> G = [&](int i, int x) {
            int L = -1, R = -1;
            {
                int low = i, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (mina.get(i, mid) == x) {
                        R = mid; low = mid + 1;
                    } else if (mina.get(i, mid) > x) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            if (R == -1) { return make_pair(-1, -1); }
            {
                int low = i, high = R;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (mina.get(mid, R) == x) {
                        L = mid; high = mid - 1; 
                    } else if (mina.get(mid, R) > x) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            return make_pair(L, R);
        };
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            int L = i, R = i;
            {
                int low = 0, high = i - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (maxa.get(mid, i) == a[i]) {
                        L = mid; high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            {
                int low = i + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (maxa.get(i, mid) == a[i]) {
                        R = mid; low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            auto [L1min, R1min] = F(i, k - a[i]);
            auto [L2min, R2min] = G(i, k - a[i]);
            if (L1min == -1 && L2min == -1) { continue; }
            if (L1min != -1) { L1min = max(L1min, L); }
            if (R2min != -1) { R2min = min(R2min, R); }
            if (L1min != -1 && L2min != -1) {
                ans += 1LL * (i - L1min + 1) * (R2min - i + 1) - 1LL * (i - (R1min + 1) + 1) * ((L2min - 1) - i + 1);
            } else if (L1min != -1) {
                ans += 1LL * (R1min - L1min + 1) * (R - i + 1);
            } else {
                ans += 1LL * (i - L + 1) * (R2min - L2min + 1);
            }
        }
        cout << ans << "\n";
    }
}
