/**
 *    author:  MaGnsi0
 *    created: 06/10/2021 02:14:18
**/
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int k;
    long long x;
    cin >> k >> x;
    vector<vector<long long>> T(k, vector<long long>(k));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> T[i][j];
        }
    }
    int n;
    cin >> n;
    vector<long long> p(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> p[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(k, 0));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < k; ++j) {
            if (i == n - 1) {
                dp[i][j] = 1;
                continue;
            }
            int l = lower_bound(T[j].begin(), T[j].end(), p[i] - x) - T[j].begin();
            int r = upper_bound(T[j].begin(), T[j].end(), p[i] + x) - T[j].begin();
            dp[i][j] = (dp[i][j] + (r ? dp[i + 1][r - 1] : 0) - (l ? dp[i + 1][l - 1] : 0) + MOD) % MOD;
        }
        for (int j = 1; j < k; ++j) {
            dp[i][j] = (dp[i][j] + dp[i][j - 1] + MOD) % MOD;
        }
    }
    cout << dp[0][k - 1];
}
