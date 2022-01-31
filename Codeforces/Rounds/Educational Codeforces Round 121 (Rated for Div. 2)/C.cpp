/**
 *    author:  MaGnsi0
 *    created: 22.01.2022 23:45:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<long long> dp(n, -1);
        function<long long(int)> solve = [&](int x) {
            if (x == n) {
                return 0LL;
            }
            if (dp[x] != -1) {
                return dp[x];
            }
            dp[x] = 1e18;
            long long start = a[x] - b[x] + 1, end = a[x];
            for (int i = x; i < n; ++i) {
                start = min(a[i] - b[i] + 1, start); 
                end = a[i];
                long long length = end - start + 1;
                if (x != 0 && start <= a[x - 1]) {
                    break;
                }
                if (i + 1 == n || a[i + 1] - b[i + 1] + 1 > end) {
                    dp[x] = min(dp[x], solve(i + 1) + length * (length + 1) / 2);
                }
            }
            return dp[x];
        };
        cout << solve(0) << "\n";
    }
}
