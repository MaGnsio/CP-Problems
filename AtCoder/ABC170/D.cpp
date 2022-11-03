/**
 *    author:  MaGnsi0
 *    created: 04/06/2021 15:57:25
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end());
    int maxe = v[n - 1];
    vector<bool> dp(maxe + 1, true);
    vector<int> cnt(maxe + 1, 0);
    for (auto& x : v) {
        cnt[x]++;
    }
    for (auto& x : v) {
        if (!dp[x]) {
            continue;
        }
        if (cnt[x] > 1) {
            dp[x] = false;
        }
        for (int i = 2 * x; i <= maxe; i += x) {
            dp[i] = false;
        }
    }
    int ans = 0;
    for (auto& x : v) {
        ans += dp[x];
    }
    cout << ans;
}
