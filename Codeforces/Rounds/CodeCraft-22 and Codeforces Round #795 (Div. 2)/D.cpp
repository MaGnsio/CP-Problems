/**
 *    author:  MaGnsi0
 *    created: 01.06.2022 16:33:53
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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        segment_tree<pair<int, int>> b(n, make_pair(INT_MIN, -1), [](pair<int, int> x, pair<int, int> y) {return max(x, y);}); 
        segment_tree<int64_t> c(n, INT64_MIN, [](int64_t x, int64_t y) {return max(x, y);});
        segment_tree<int64_t> d(n, INT64_MAX, [](int64_t x, int64_t y) {return min(x, y);});
        for (int i = 0; i < n; ++i) {
            b.update(i, make_pair(a[i], i));
            if (i) {
                a[i] += a[i - 1];
            }
            c.update(i, a[i]);
            d.update(i, a[i]);
        }
        function<bool(int, int)> solve = [&](int l, int r) {
            if (l >= r) {
                return true;
            }
            int x, m;
            tie(x, m) = b.query(l, r + 1);
            int64_t maxp = c.query(m, r + 1);
            int64_t minp = (l ? d.query(l - 1, m) : min(d.query(l, m), int64_t(0)));
            if (x < maxp - minp) {
                return false;
            }
            return (solve(l, m - 1) && solve(m + 1, r));
        };
        cout << (solve(0, n - 1) ? "YES" : "NO") << "\n";
    }
}
