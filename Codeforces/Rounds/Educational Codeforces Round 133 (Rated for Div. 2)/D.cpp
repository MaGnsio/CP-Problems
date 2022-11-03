/**
 *    author:  MaGnsi0
 *    created: 13.08.2022 15:30:00
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int64_t> dp1(n + 1), ans(n + 1);
    dp1[0] = 1;
    for (int i = k; i <= n; ++i) {
        vector<int64_t> dp2(n + 1);
        for (int j = i; j <= n; ++j) {
            dp2[j] = (dp2[j - i] + dp1[j - i]);
            dp2[j] %= MOD;
        }
        for (int j = 0; j <= n; ++j) {
            ans[j] += dp2[j];
            ans[j] %= MOD;
        }
        swap(dp1, dp2);
        if (dp1 == vector<int64_t>(n + 1, 0)) {
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
}
