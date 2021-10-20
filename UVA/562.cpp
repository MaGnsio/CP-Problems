/**
 *    author:  MaGnsi0
 *    created: 04/09/2021 19:39:46
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, w = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            w += v[i];
        }
        vector<int> dp(w / 2 + 1, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = w / 2; j; --j) {
                if (v[i] <= j) {
                    dp[j] = max(dp[j], v[i] + dp[j - v[i]]);
                }
            }
        }
        cout << w - 2 * dp[w / 2] << "\n";
    }
}
