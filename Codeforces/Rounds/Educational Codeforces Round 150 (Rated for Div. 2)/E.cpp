/**
 *    author:  MaGnsi0
 *    created: 14.06.2023 04:07:59
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
        segment_tree<pair<int, int>> a(n, make_pair(-1, -1), [&](auto x, auto y) { return max(x, y); });
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.update(i, make_pair(x, i));
        }
        int64_t m;
        cin >> m;
        vector<int64_t> b(n + 1);
        function<void(int, int, int)> solve = [&](int l, int r, int row) {
            if (l > r) { return; }
            auto x = a.query(l, r + 1);
            b[r - l + 1] += row - x.first;
            solve(l, x.second - 1, x.first);
            solve(x.second + 1, r, x.first);
        };
        solve(0, n - 1, n);
        int64_t ans = 0;
        for (int i = n; i > 0; --i) {
            int64_t need = min(b[i] * i, m);
            ans += (need / i) * (i - 1);
            m -= i * (need / i);
            if (need % i) {
                ans += need % i - 1;
                m -= need % i;
            }
        }
        cout << ans << "\n";
    }
}
