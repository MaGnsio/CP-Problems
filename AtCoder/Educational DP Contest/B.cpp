/**
 *    author:  MaGnsi0
 *    created: 02/09/2021 15:29:05
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1, l = 0; l < k && j < n; ++j, ++l) {
            dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }
    cout << dp[n - 1];
}
