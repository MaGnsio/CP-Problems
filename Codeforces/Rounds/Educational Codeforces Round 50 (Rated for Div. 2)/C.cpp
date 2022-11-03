/**
 *    author:  MaGnsi0
 *    created: 11.09.2022 22:53:31
**/
#include <bits/stdc++.h>

using namespace std;

int64_t F(int64_t x) {
    string s = to_string(x);
    int n = (int)s.size();
    vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(4, vector<int64_t>(2, -1)));
    function<int64_t(int, int, int)> solve = [&](int j, int cnt, int t) {
        if (j == n) {
            return int64_t(cnt != 0);
        }
        if (dp[j][cnt][t] != -1) {
            return dp[j][cnt][t];
        }
        dp[j][cnt][t] = 0;
        if (t == 0) {
            dp[j][cnt][t] += solve(j + 1, cnt, 0);
        } else {
            dp[j][cnt][t] += solve(j + 1, cnt, s[j] == '0');
        }
        if (cnt < 3) {
            for (int i = 1; i <= 9; ++i) {
                if (t == 0) {
                    dp[j][cnt][t] += solve(j + 1, cnt + 1, 0);
                } else {
                    if (s[j] - '0' >= i) {
                        dp[j][cnt][t] += solve(j + 1, cnt + 1, s[j] - '0' == i);
                    }
                }
            }
        }
        return dp[j][cnt][t];
    };
    return solve(0, 0, 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t L, R;
        cin >> L >> R;
        cout << F(R) - F(L - 1) << "\n";
    }
}
