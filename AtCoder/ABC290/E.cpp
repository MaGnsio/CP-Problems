/**
 *    author:  MaGnsi0
 *    created: 19.02.2023 14:16:20
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int64_t ans = 0;
    vector<vector<int64_t>> b(n);
    segment_tree<int64_t> c(n + 1, 0, [](int64_t x, int64_t y) { return x + y; });
    segment_tree<int64_t> d(n + 1, 0, [](int64_t x, int64_t y) { return x + y; });
    for (int64_t i = n - 1; i >= 0; --i) {
        ans += c.query(0, i + 1);
        ans += (i + 1) * d.query(i + 1, n + 1);
        if (!b[a[i] - 1].empty()) {
            int64_t low = 0, high = b[a[i] - 1].size() - 1, j = -1;
            while (low <= high) {
                int64_t mid = (low + high) / 2;
                int64_t x = b[a[i] - 1][mid] - (mid ? b[a[i] - 1][mid - 1] : 0);
                if (x <= i + 1) {
                    j = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (j != -1) {
                ans -= b[a[i] - 1][j];
                ans -= (i + 1) * (b[a[i] - 1].size() - j - 1);
            } else {
                ans -= (i + 1) * b[a[i] - 1].size();
            }
        }
        b[a[i] - 1].push_back(n - i);
        if (b[a[i] - 1].size() > 1) {
            int64_t j = b[a[i] - 1].size();
            b[a[i] - 1][j - 1] += b[a[i] - 1][j - 2];
        }
        c.update(n - i, n - i);
        d.update(n - i, 1);
    }
    cout << ans;
}
