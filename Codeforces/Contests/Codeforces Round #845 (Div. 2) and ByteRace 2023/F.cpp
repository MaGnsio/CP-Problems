/**
 *    author:  MaGnsi0
 *    created: 02.02.2023 02:12:45
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T, class F = function<T(const T&, const T&)>>
struct sparse_table {
    int n;
    vector<vector<T>> mat;
    F func;
    sparse_table(const int n, const F& f) : func(f) {
        this -> n = n;
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        for (int i = 0; i < n; ++i) {
            mat[0].push_back(i);
        }
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

struct node {
    int C[2];
    node() {
        C[0] = C[1] = -1;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        //prefix xor
        for (int i = 1; i < n; ++i) {
            a[i] = a[i] ^ a[i - 1];
        }
        //trie
        vector<node> t[n + 1];
        for (int i = 0; i <= n; ++i) {
            t[i].push_back(node());
        }
        function<void(int, int)> insert = [&](int j, int x) {
            int k = 0;
            for (int i = 30; i >= 0; --i) {
                int cur_bit = (x >> i) & 1;
                if (t[j][k].C[cur_bit] == -1) {
                    t[j][k].C[cur_bit] = (int)t[j].size();
                    t[j].push_back(node());
                }
                k = t[j][k].C[cur_bit];
            }
        };
        function<int(int, int)> F = [&](int j, int x) {
            int k = 0, ans = 0;
            for (int i = 30; i >= 0; --i) {
                int cur_bit = (x >> i) & 1;
                if (t[j][k].C[cur_bit ^ 1] != -1) {
                    ans |= (1 << i);
                    k = t[j][k].C[cur_bit ^ 1];
                } else {
                    k = t[j][k].C[cur_bit];
                }
            }
            return ans;
        };
        for (int i = 0; i < n; ++i) {
            if (i) {
                insert(i, a[i - 1]);
            } else {
                insert(i, 0);
            }
            insert(i, a[i]);
        }
        insert(n, a[n - 1]);
        //max sparse_table 
        sparse_table<int> c(n + 1, [&](int i, int j) {
                int x = a[i] ^ (i ? a[i - 1] : 0);
                int y = a[j] ^ (j ? a[j - 1] : 0);
                return (x >= y ? i : j);
            });
        //actual solution
        int ans = 0;
        function<void(int, int)> solve = [&](int l, int r) {
            if (l >= r) {
                return;
            }
            if (l + 1 == r) {
                int x = a[l] ^ (l ? a[l - 1] : 0);
                int y = a[r] ^ (r ? a[r - 1] : 0);
                ans = max(ans, min(x, y));
                insert(l, a[r]);
                return;
            }
            int j = c.get(l, r);
            int x = a[j] ^ (j ? a[j - 1] : 0);
            solve(l, j - 1);
            solve(j + 1, r);
            if (r - j > j - l) {
                for (int i = l; i <= j; ++i) {
                    ans = max(ans, F(j + 1, (i ? a[i - 1] : 0) ^ x));
                }
                swap(t[l], t[j + 1]);
                for (int i = l; i < j; ++i) {
                    insert(l, a[i]);
                }
                if (l) {
                    insert(l, a[l - 1]);
                } else {
                    insert(l, 0);
                }
            } else {
                for (int i = j; i <= r; ++i) {
                    ans = max(ans, F(l, a[i] ^ x));
                }
                for (int i = j; i <= r; ++i) {
                    insert(l, a[i]);
                }
            }
        };
        solve(0, n - 1);
        cout << ans << "\n";
    }
}
