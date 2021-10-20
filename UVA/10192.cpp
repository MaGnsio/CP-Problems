/**
 *    author:  MaGnsi0
 *    created: 04/09/2021 18:40:35
**/
#include <bits/stdc++.h>
using namespace std;

bool input(string& a, string& b) {
    getline(cin, a);
    if (a[0] == '#') {
        return false;
    }
    getline(cin, b);
    return true;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T = 1;
    string a, b;
    while (input(a, b)) {
        int n = a.size() + 1, m = b.size() + 1;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]));
            }
        }
        cout << "Case #" << T++ << ": you can visit at most " << dp[n - 1][m - 1] << " cities.\n";
    }
}
