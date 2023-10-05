/**
 *    author:  MaGnsi0
 *    created: 18.09.2023 21:21:56
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 9005;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> b(n + 1, vector<int>(N, n));
        for (int i = n - 1; i >= 0; --i) {
            int mex = 0;
            b[i] = b[i + 1];
            vector<bool> found(N, false);
            for (int j = i; j < n; ++j) {
                found[a[j]] = true;
                while (found[mex]) { mex++; }
                b[i][mex] = min(b[i][mex], j);
            }
        }
        vector<int> dp(N, n);
        vector<bool> done(N, false);
        dp[0] = -1;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = 0; j < n; ++j) {
                if (!done[j] && (k == -1 || dp[j] < dp[k])) {
                    k = j;
                }
            }
            if (k == -1 || dp[k] == n) { break; }
            done[k] = true;
            for (int j = 0; j < N; ++j) {
                if ((j ^ k) >= N) { continue; }
                dp[j] = min(dp[j], b[dp[k] + 1][j ^ k]);
            }
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (dp[i] < n) { ans = i; }
        }
        cout << ans << "\n";
    }
}
