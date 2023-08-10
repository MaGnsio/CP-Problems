/**
 *    author:  MaGnsi0
 *    created: 09.07.2023 22:04:30
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("task.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> dp(N, -1);
        dp[0] = n;
        for (int i = 1; i < N; ++i) {
            int j = lower_bound(a.begin(), a.end(), i) - a.begin();
            if (j < n && a[j] == i) {
                dp[i] = dp[i - 1] - 1;
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }
        int ans = n + 1;
        for (int i = 1; i < N; ++i) {
            ans = min(ans, dp[i]);
        }
        cout << ans << "\n";
    }
}
