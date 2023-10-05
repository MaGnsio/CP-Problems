/**
 *    author:  MaGnsi0
 *    created: 20.05.2022 01:51:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        is_palindrome[i][i] = true;
        if (i) {
            is_palindrome[i - 1][i] = (s[i - 1] == s[i]);
        }
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 0; i + j < n; ++j) {
            is_palindrome[j][i + j] = (is_palindrome[j + 1][i + j - 1] && s[j] == s[i + j]);
        }
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(n, -1));
    function<int64_t(int, int)> solve = [&](int l, int r) {
        if (l == r) {
            return int64_t(1);
        }
        if (r - l == 1) {
            return int64_t(2 + is_palindrome[l][r]);
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        dp[l][r] = solve(l + 1, r) + solve(l, r - 1) - solve(l + 1, r - 1) + is_palindrome[l][r];
        return dp[l][r];
    };
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << solve(l - 1, r - 1) << "\n";
    }
}
