/**
 *    author:  MaGnsi0
 *    created: 21.05.2023 22:48:38
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e16;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, p;
    cin >> n >> p;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        char _; cin >> _;
        cin >> a[i];
    }
    vector<int64_t> b(10);
    for (int i = 0; i < 10; ++i) {
        cin >> b[i];
    }
    vector<vector<int64_t>> dp(10, vector<int64_t>(10, OO));
    for (int i = 0; i < 10; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i < 10; ++i) {
        dp[i][1] = b[i];
        for (int j = 2; j <= i; ++j) {
            for (int k = 1; k < i; ++k) {
                dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + b[k]);
            }
        }
        for (int j = 1; j < 10; ++j) {
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }
    function<int64_t(int64_t)> F = [&](int64_t x) {
        int64_t res = OO;
        string s = to_string(x);
        for (int i = 1; i < 10; ++i) {
            int64_t val = i * p;
            for (char c : s) { val += dp[c - '0'][i]; }
            res = min(res, val);
        }
        return res;
    };
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        int64_t val = p * a[i];
        for (int j = 0; j <= min(a[i], int64_t(100)); ++j) {
            int64_t x = a[i] - j;
            val = min(F(x) + p * j, val);
        }
        ans += val;
    }
    cout << ans;
}
