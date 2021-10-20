/**
 *    author:  MaGnsi0
 *    created: 20/09/2021 14:41:10
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        c *= (n - i);
        for (int i = x; i; --i) {
            if (i < c) {
                continue;
            }
            dp[i] = max(dp[i], dp[i - c] + 1);
        }
    }
    cout << dp[x];
}
