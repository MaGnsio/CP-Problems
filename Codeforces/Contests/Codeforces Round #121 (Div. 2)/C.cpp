/**
 *    author:  MaGnsi0
 *    created: 29/09/2021 20:55:11
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<string> S(n);
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }
    vector<vector<int>> dp(26, vector<int>(26, 0));
    for (int i = 0; i < n; ++i) {
        int length = (int)S[i].size();
        int l = S[i].front() - 'a';
        int r = S[i].back() - 'a';
        for (int j = 0; j < 26; ++j) {
            if (dp[j][l]) {
                dp[j][r] = max(dp[j][r], dp[j][l] + length);
            }
        }
        dp[l][r] = max(dp[l][r], length);
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans = max(ans, dp[i][i]);
    }
    cout << ans;
}

//the first letter of the abbreviated name of the heir coincides with the last letter of the abbreviated name of the predecessor.
//the first letter of the abbreviated name of the first king coincides with the last letter of the abbreviated name of the last king.
