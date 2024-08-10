/**
 *    author:  MaGnsi0
 *    created: 10.08.2024 19:14:39
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x; cin >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        segment_tree<pair<int, int>> b(n, make_pair(-1, -1), [](pair<int, int> x, pair<int, int> y) {
                                        return max(x, y);
                                    });
        for (int i = 0; i < n; ++i) {
            b.update(i, make_pair(a[i], i));
        }
        vector<int64_t> c(n);
        for (int i = 0; i < n; ++i) {
            c[i] = a[i] + (i ? c[i - 1] : 0);
            
        }
        function<int(int, int, int)> solve = [&](int l, int r, int pass) {
            if (l > r) { return 0; }
            if (l == r) { return int(a[l] >= pass); }
            auto [x, j] = b.query(l, r + 1);
            if (c[r] - (l ? c[l - 1] : 0) >= pass) {
                return solve(l, j - 1, x) + solve(j + 1, r, x) + 1;
            }
            return 0;
        };
        int ans = solve(0, n - 1, 0);
        cout << ans << "\n";
    }
}
