/**
 *    author:  MaGnsi0
 *    created: 06.09.2023 01:55:54
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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    function<bool(int)> F = [&](int x) {
        vector<int> next(n + 1, n);
        for (int i = n - 1; i >= 0; --i) {
            next[i] = (a[i] >= x ? i : next[i + 1]);
        }
        vector<int> dp(n + 1);
        segment_tree<int> b(n + 1, 0, [](int x, int y) { return max(x, y); });
        dp[n] = 1, b.update(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            int low = max(i + l - 1, next[i]) + 1;
            int high = min(i + r - 1, n - 1) + 1;
            if (low > high) {
                dp[i] = 0, b.update(i, 0);
            } else {
                dp[i] = b.query(low, high + 1);
                b.update(i, dp[i]);
            }
        }
        return dp[0];
    };
    int low = 1, high = 1e9, ans = 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (F(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans;
}
