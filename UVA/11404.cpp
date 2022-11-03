/**
 *    author:  MaGnsi0
 *    created: 08.09.2022 18:38:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    while (cin >> s) {
        int n = (int)s.size();
        vector<vector<pair<int, string>>> dp(n, vector<pair<int, string>>(n, {-1, ""}));
        function<pair<int, string>(int, int)> solve = [&](int l, int r) {
            if (l == r) {
                return dp[l][r] = make_pair(1, string(1, s[l]));
            }
            if (l > r) {
                return make_pair(0, string(0, 'X'));
            }
            if (dp[l][r].first != -1) {
                return dp[l][r];
            }
            if (s[l] == s[r]) {
                dp[l][r] = {solve(l + 1, r - 1).first + 2, s[l] + solve(l + 1, r - 1).second + s[r]};
                return dp[l][r];
            }
            pair<int, string> ans1 = solve(l, r - 1), ans2 = solve(l + 1, r);
            if (ans1.first > ans2.first) {
                return dp[l][r] = ans1;
            } else if (ans2.first > ans1.first) {
                return dp[l][r] = ans2;
            } else if (ans1.second < ans2.second) {
                return dp[l][r] = ans1;
            } else {
                return dp[l][r] = ans2;
            }
        };
        cout << solve(0, n - 1).second << endl;
    }
}
