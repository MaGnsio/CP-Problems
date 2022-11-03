/**
 *    author:  MaGnsi0
 *    created: 07.09.2022 23:34:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    while (cin >> s) {
        int n = (int)s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int, int)> solve = [&](int l, int r) {
            if (r - l + 1 <= 2) {
                return dp[l][r] = s[l] != s[r];
            }
            if (dp[l][r] != -1) {
                return dp[l][r];
            }
            dp[l][r] = 1 + solve(l, r - 1);
            dp[l][r] = min(dp[l][r], solve(l + 1, r) + 1);
            if (s[l] == s[r]) {
                dp[l][r] = min(dp[l][r], solve(l + 1, r - 1));
            }
            return dp[l][r];
        };
        bool last = false;
        string ans = "";
        function<void(int, int)> build = [&](int l, int r) {
            if (l == r) {
                ans += s[l];
                return;
            }
            if (l + 1 == r) {
                ans += s[l];
                if (s[l] == s[r]) {
                    last = true;
                }
                if (s[l] != s[r]) {
                    ans += s[r];
                }
                return;
            }
            int res1 = (s[l] == s[r] ? solve(l + 1, r - 1) : INT_MAX);
            int res2 = solve(l, r - 1) + 1;
            int res3 = solve(l + 1, r) + 1;
            if (res1 <= res2 && res1 <= res3) {
                ans += s[l];
                build(l + 1, r - 1);
            } else if (res2 <= res1 && res2 <= res3) {
                ans += s[r];
                build(l, r - 1);
            } else {
                ans += s[l];
                build(l + 1, r);
            }
        };
        build(0, n - 1);
        ans.insert(ans.end(), ans.rbegin() + !last, ans.rend());
        cout << solve(0, n - 1) << " " << ans << endl;
    }
}
