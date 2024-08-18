/**
 *    author:  MaGnsi0
 *    created: 18.08.2024 20:46:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t s; cin >> s;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    vector<int64_t> dp(n);
    for (int i = n - 1; i >= 0; --i) {
        int low = i, high = n - 1, j = i;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] - (i ? a[i - 1] : 0) <= s) {
                j = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        dp[i] = (n - i) + (j == n - 1 ? 0 : dp[j + 1]);
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[i];
    }
    cout << ans;
}
