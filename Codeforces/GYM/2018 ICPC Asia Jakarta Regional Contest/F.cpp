/**
 *    author:  MaGnsi0
 *    created: 04.11.2023 19:31:42
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

pair<int64_t, int> F(pair<int64_t, int> x, pair<int64_t, int> y) {
    return max(x, y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t m; cin >> m;
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<pair<int64_t, int>> d(n);
    for (int i = 0; i < n; ++i) {
        d[i] = make_pair(b[i], -i);
    }
    for (int i = 1; i < n; ++i) {
        b[i] += b[i - 1];
    }
    sparse_table<pair<int64_t, int>> e(d, F);
    segment_tree<int64_t> c(n, 0, [](int64_t x, int64_t y) { return x + y; });
    function<int(int64_t)> get_last_solve = [&](int64_t cur_time) {
        int low = 0, high = n - 1, last_solve = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (b[mid] + c.query(0, mid + 1) < cur_time) {
                last_solve = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last_solve;
    };
    function<int()> get_cant_do = [&]() {
        int low = 0, high = n - 1, cant_do = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (b[mid] + c.query(0, mid + 1) > m) {
                cant_do = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return cant_do;
    };
    int64_t X = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > m) { break; }
        X++;
    }
    if (X == 0) {
        cout << -1;
        return 0;
    }
    vector<int64_t> ans;
    for (int i = 0; i < X; ++i) {
        int64_t cur_time = a[i];
        int64_t last_solve = get_last_solve(cur_time);
        int64_t cant_do = get_cant_do();
        if (last_solve == n - 1) { break; }
        if (last_solve + 1 > min(cant_do, X) - 1) { break; }
        auto [loss, j] = e.get(last_solve + 1, min(cant_do - 1, X - 1)); j = -j;
        int64_t t = b[j] + c.query(0, j + 1);
        if (!ans.empty() && t <= ans.back()) { break; }
        ans.push_back(t);
        c.update(j, loss);
    }
    if (b[X - 1] + c.query(0, X) <= m) {
        cout << -1;
        return 0;
    }
    cout << (int)ans.size() << "\n";
    for (int64_t x : ans) {
        cout << x << " ";
    }
}
