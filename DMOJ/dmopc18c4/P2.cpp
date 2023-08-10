/**
 *    author:  MaGnsi0
 *    created: 27.03.2023 22:31:47
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 2 * 700 * 700 + 5, O = 700 * 700, OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k = 0;
    vector<vector<bool>> dp(2, vector<bool>(M, false));
    dp[0][O] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < M; ++j) {
            if (dp[k][j] == false) { continue; }
            int val = j - O;
            dp[k ^ 1][val + a[i] + O] = true;
            dp[k ^ 1][val - a[i] + O] = true;
        }
        dp[k] = vector<bool>(M, false);
        k ^= 1;
    }
    int ans = OO;
    for (int i = 0; i < M; ++i) {
        if (dp[k][i]) {
            ans = min(ans, abs(i - O));
        }
    }
    cout << ans;
}
