/**
 *    author:  MaGnsi0
 *    created: 02.09.2023 13:22:51
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> s(n);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        a[i].resize(s[i]);
        for (int j = 0; j < s[i]; ++j) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    int minb = a[0].back();
    vector<int> b(n); b[0] = minb;
    set<int> S; S.insert(b[0]);
    for (int i = 1; i < n; ++i) {
        int j = lower_bound(a[i].begin(), a[i].end(), minb) - a[i].begin();
        if (j == 0) {
            int x = a[i][0];
            auto it = S.upper_bound(x);
            assert(it != S.begin());
            if (it == S.end()) {
                b[i] = a[i].back();
            } else {
                int z = *it;
                int k = lower_bound(a[i].begin(), a[i].end(), z) - a[i].begin();
                assert(k);
                b[i] = a[i][k - 1];
            }
        } else {
            b[i] = a[i][j - 1];
        }
        minb = min(minb, b[i]);
        S.insert(b[i]);
    }
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
            if (b[i] == b[j]) { return i < j; }
            return b[i] < b[j];
        });
    vector<vector<int64_t>> dp(n);
    for (int i = 0; i < n; ++i) {
        int x = I[i];
        dp[i].resize(s[x]);
    }
    for (int i = 0; i < s[I[n - 1]]; ++i) {
        dp[n - 1][i] = 1;
    }
    for (int i = s[I[n - 1]] - 2; i >= 0; --i) {
        dp[n - 1][i] += dp[n - 1][i + 1];
        dp[n - 1][i] %= MOD;
    }
    for (int i = n - 2; i >= 0; --i) {
        int x = I[i], y = I[i + 1];
        for (int j = 0; j < s[x]; ++j) {
            if (x < y) {
                int k = lower_bound(a[y].begin(), a[y].end(), a[x][j]) - a[y].begin();
                if (k == s[y]) { continue; }
                dp[i][j] = dp[i + 1][k];
            } else {
                int k = upper_bound(a[y].begin(), a[y].end(), a[x][j]) - a[y].begin();
                if (k == s[y]) { continue; }
                dp[i][j] = dp[i + 1][k];
            }
        }
        for (int j = s[x] - 2; j >= 0; --j) {
            dp[i][j] += dp[i][j + 1];
            dp[i][j] %= MOD;
        }
    }
    int64_t ans = dp[0][0];
    cout << ans;
}
