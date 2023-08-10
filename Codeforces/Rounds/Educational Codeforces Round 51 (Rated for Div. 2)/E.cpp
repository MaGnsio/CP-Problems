/**
 *    author:  MaGnsi0
 *    created: 02.08.2023 14:33:07
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

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

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) { z[i] = min(r - i, z[i - l]); }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) { z[i]++; }
        if (i + z[i] > r) { l = i, r = i + z[i]; }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string A, L, R;
    cin >> A >> L >> R;
    int n = (int)A.size();
    int m = (int)L.size();
    int k = (int)R.size();
    vector<int> Z1 = z_function(L + "#" + A);
    vector<int> Z2 = z_function(R + "#" + A);
    vector<int64_t> dp(n + 1);
    segment_tree<int64_t> S(n + 1, 0, [&](int64_t x, int64_t y) { return (x + y) % MOD; });
    dp[n] = 1, S.update(n, 1);
    for (int i = n - 1; i >= 0; --i) {
        if (A[i] == '0') {
            dp[i] = (L == "0") * dp[i + 1];
            S.update(i, dp[i]);
            continue;
        }
        int low = min(i + m - 1, n - 1);
        int high = min(i + k - 1, n - 1);
        if (low - i + 1 == m) {
            int j = i + Z1[i + m + 1];
            low += (j < n) && (j - i < m) && (A[j] < L[j - i]);
        }
        if (high - i + 1 == k) {
            int j = i + Z2[i + k + 1];
            high -= (j < n) && (j - i < k) && (A[j] > R[j - i]);
        }
        if (low <= high && low - i + 1 >= m) {
            dp[i] = S.query(low + 1, high + 2);
        }
        S.update(i, dp[i]);
    }
    int64_t ans = dp[0];
    cout << ans;
}
