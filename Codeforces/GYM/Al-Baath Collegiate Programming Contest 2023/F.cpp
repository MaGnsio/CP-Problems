/**
 *    author:  MaGnsi0
 *    created: 07.07.2023 01:57:49
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e16;

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
        int64_t n, k;
        cin >> n >> k;
        vector<int64_t> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            string s;
            cin >> s;
            int m = (int)s.size();
            for (int j = 0; j < m / 2; ++j) {
                a[i] += s[j] != s[m - j - 1];
            }
        }
        for (int i = 1; i <= n; ++i) {
            a[i] += a[i - 1];
        }
        vector<int64_t> b(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; ++i) {
            b[i] += b[i - 1];
        }
        segment_tree<int64_t> c(n + 1, -OO, [](int64_t x, int64_t y) { return max(x, y); });
        for (int i = 0; i <= n; ++i) {
            c.update(i, b[i]);
        }
        int64_t ans = 0;
        for (int i = 1; i <= n; ++i) {
            int low = i, high = n, j = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[mid] - a[i - 1] <= k) {
                    j = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (j == -1) { continue; }
            ans = max(ans, c.query(i, j + 1) - b[i - 1]);
        }
        cout << ans << "\n";
    }
}
