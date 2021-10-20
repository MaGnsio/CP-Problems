/**
 *    author:  MaGnsi0
 *    created: 05/09/2021 14:47:11
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n), w(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i] >> w[i];
        }
        int m;
        cin >> m;
        vector<int> p(m);
        for (int i = 0; i < m; ++i) {
            cin >> p[i];
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> dp(p[i] + 1, 0);
            for (int j = 0; j < n; ++j) {
                for (int k = p[i]; k; --k) {
                    if (w[j] <= k) {
                        dp[k] = max(dp[k], dp[k - w[j]] + v[j]);
                    }
                }
            }
            res += dp[p[i]];
        }
        cout << res << "\n";
    }
}
