/**
 *    author:  MaGnsi0
 *    created: 04/09/2021 22:14:24
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = (x == 1 || x == 3);
        b[i] = (x == 2 || x == 3);
    }
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = a[0], dp[0][1] = b[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = a[i] + max({dp[i - 1][1], (i > 1 ? dp[i - 2][0] : 0), (i > 1 ? dp[i - 2][1] : 0)});
        dp[i][1] = b[i] + max({dp[i - 1][0], (i > 1 ? dp[i - 2][1] : 0), (i > 1 ? dp[i - 2][0] : 0)});
    }
    cout << n - max(dp[n - 1][0], dp[n - 1][1]);
}
