/**
 *    author:  MaGnsi0
 *    created: 05.08.2024 20:29:49
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (k >= n) {
            sort(a.begin(), a.end());
            cout << a[(n - 1) / 2] << "\n";
            continue;
        }
        int m = (n % k) + (n % k == 0) * k;
        function<bool(int)> F = [&](int x) {
            vector<int> dp(m, -OO);
            for (int i = 0; i < n; ++i) {
                int j = i % k;
                if (j >= m) { continue; }
                dp[j] = max(dp[j], (j ? dp[j - 1] : 0) + (a[i] >= x ? 1 : -1));
            }
            return dp[m - 1] > 0;
        };
        int low = 1, high = 1e9, ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (F(mid)) {
                ans = mid, low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
