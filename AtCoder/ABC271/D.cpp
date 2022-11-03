/**
 *    author:  MaGnsi0
 *    created: 01.10.2022 14:18:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (dp[i - 1][j]) {
                if (j + a[i - 1] <= s) { dp[i][j + a[i - 1]] = true; }
                if (j + b[i - 1] <= s) { dp[i][j + b[i - 1]] = true; }
            }
        }
    }
    if (dp[n][s]) {
        string ans = "";
        for (int i = n - 1; i >= 0; --i) {
            if (s >= a[i] && dp[i][s - a[i]]) {
                ans += "H";
                s -= a[i];
            } else {
                ans += "T";
                s -= b[i];
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "Yes\n" << ans;
    } else {
        cout << "No";
    }
}
