/**
 *    author:  MaGnsi0
 *    created: 15.08.2022 06:48:03
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
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segment_tree<int64_t> st(n, (int64_t)1e10, [](int x, int y) { return min(x, y); });
    for (int i = 0; i < n; ++i) {
        st.update(i, a[i]);
    }
    vector<int64_t> dp(n);
    dp[0] = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) {
            dp[i] = a[i] + dp[i - 1];
        } else {
            int l = 0, r = i - 1, j = 0;
            while (l <= r) {
                int m = (l + r) / 2;
                if (a[i] < st.query(m, i)) {
                    j = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            dp[i] = (j ? dp[j - 1] : 0) + (i - j + 1) * a[i];
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}
