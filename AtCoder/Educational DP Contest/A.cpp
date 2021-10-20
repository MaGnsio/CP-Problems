/**
 *    author:  MaGnsi0
 *    created: 02/09/2021 15:21:34
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    vector<int> dp(n, 0);
    for (int i = 1; i < n; ++i) {
        if (i == 1) {
            dp[i] = abs(h[i] - h[i - 1]);
        } else {
            dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }
    cout << dp[n - 1];
}
