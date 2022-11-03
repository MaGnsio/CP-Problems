/**
 *    author:  MaGnsi0
 *    created: 18/09/2021 13:55:11
**/
#include <bits/stdc++.h>
using namespace std;

const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, OO));
    dp[0][0] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = x; i >= 0; --i) {
            for (int j = y; j >= 0; --j) {
                int a = min(x, v[k].first + i);
                int b = min(y, v[k].second + j);
                dp[a][b] = min(dp[a][b], dp[i][j] + 1);
            }
        }
    }
    cout << (dp[x][y] == OO ? -1 : dp[x][y]);
}
