/**
 *    author:  MaGnsi0
 *    created: 02/09/2021 20:37:29
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        vector<vector<bool>> dp(n, vector<bool>(k, false));
        dp[0][(v[0] % k + k) % k] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (!dp[i - 1][j]) {
                    continue;
                }
                dp[i][(j + v[i] % k + k) % k] = true;
                dp[i][(j - v[i] % k + k) % k] = true;
            }
        }
        cout << (dp[n - 1][0] ? "Divisible" : "Not divisible") << "\n";
    }
}
