/**
 *    author:  MaGnsi0
 *    created: 23.11.2022 17:12:41
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> p(n + 1, 0);
        p[n] = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (a[i] > a[n - i - 1]) {
                p[n - i - 1] = a[i] - a[n - i - 1]; 
            } else {
                p[i] = a[n - i - 1] - a[i];
            }
        }
        segment_tree<int> b(n, n, [&](int x, int y) { return (p[x] < p[y] ? x : y); });
        for (int i = 0; i < n; ++i) {
            b.update(i, i);
        }
        function<int64_t(int, int, int)> solve = [&](int l, int r, int offset) {
            if (l > r) {
                return int64_t(0);
            }
            if (l == r) {
                return int64_t(p[l] - offset);
            }
            int m = b.query(l, r + 1);
            return solve(l, m - 1, p[m]) + (p[m] - offset) + solve(m + 1, r, p[m]);
        };
        cout << solve(0, n - 1, 0) << "\n";
    }
}
