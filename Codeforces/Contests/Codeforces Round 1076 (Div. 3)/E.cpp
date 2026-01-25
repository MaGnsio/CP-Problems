/**
 *    author:  MaGnsi0
 *    created: 25.01.2026 17:04:44
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<bool> have(n + 1, false);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; have[x] = true;
        }
        vector<int> dp(n + 1, OO);
        for (int x = 1; x <= n; ++x) {
            if (have[x]) { dp[x] = 1; continue; }
            for (int y = 1; y * y <= x; ++y) {
                if (x % y) { continue; }
                if (have[y]) {
                    dp[x] = min(dp[x], dp[x / y] + 1);
                }
                if (have[x / y]) {
                    dp[x] = min(dp[x], dp[y] + 1);
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << (dp[i] == OO ? -1 : dp[i]) << " ";
        }
        cout << "\n";
    }
}
