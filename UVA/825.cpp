/**
 *    author:  MaGnsi0
 *    created: 04/09/2021 23:24:05
**/
#include <bits/stdc++.h>
using namespace std;

int solve(int& n, int& m, vector<vector<int>>& dp, int i, int j) {
    if (i >= n || j >= m) {
        return 0;
    }
    if (dp[i][j] == -2) {
        return 0;
    }
    if (i == n - 1 && j == m - 1) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    return dp[i][j] = solve(n, m, dp, i + 1, j) + solve(n, m, dp, i, j + 1);
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        cin.ignore();
        int n, m;
        cin >> n >> m;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            string s;
            getline(cin, s);
            stringstream cis(s);
            int c;
            cis >> c;
            while (cis >> c) {
                dp[i][c - 1]--;
            }
        }
        cout << solve(n, m, dp, 0, 0) << "\n" << (T ? "\n" : "");
    }
}
