/**
 *    author:  MaGnsi0
 *    created: 16/07/2021 13:24:42
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> b(N, 0), dp(N, 0);
    for (int i = 0, j; i < n; ++i) {
        cin >> j;
        cin >> b[j];
    }
    dp[0] = (b[0] > 0);
    for (int i = 1; i < N; ++i) {
        if (!b[i]) {
            dp[i] = dp[i - 1];
        } else {
            if (b[i] >= i) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i - b[i] - 1] + 1;
            }
        }
    }
    int ans = n;
    for (int i = 1; i < N; ++i) {
        ans = min(ans, n - dp[i]);
    }
    cout << ans;
}
