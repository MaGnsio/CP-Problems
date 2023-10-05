/**
 *    author:  MaGnsi0
 *    created: 22.02.2022 04:37:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> n(3);
    for (int i = 0; i < 3; ++i) {
        cin >> n[i];
    }
    vector<vector<int>> a(3);
    for (int i = 0; i < 3; ++i) {
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; ++j) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    vector<vector<vector<int>>> dp(n[0] + 1, vector<vector<int>>(n[1] + 1, vector<int>(n[2] + 1, -1)));
    function<int(int, int, int)> solve = [&](int r, int g, int b) {
        if ((r > 0) + (g > 0) + (b > 0) < 2) {
            return (dp[r][g][b] = 0);
        }
        int& ans = dp[r][g][b];
        if (ans != -1) {
            return ans;
        }
        ans = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                vector<int> idx(3);
                idx[0] = r - (i == 0 || j == 0);
                idx[1] = g - (i == 1 || j == 1);
                idx[2] = b - (i == 2 || j == 2);
                if (idx[i] < 0 || idx[j] < 0) {
                    continue;
                }
                ans = max(ans, a[i][idx[i]] * a[j][idx[j]] + solve(idx[0], idx[1], idx[2]));
            }
        }
        return ans;
    };
    cout << solve(n[0], n[1], n[2]);
}
