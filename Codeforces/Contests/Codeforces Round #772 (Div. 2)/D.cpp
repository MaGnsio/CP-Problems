/**
 *    author:  MaGnsi0
 *    created: 20.02.2022 16:26:28
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    set<int> nodes;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        bool take = true;
        while (x) {
            if (nodes.count(x)) {
                take = false;
                break;
            }
            if (x & 1) {
                x /= 2;
            } else if (x % 4 == 0) {
                x /= 4;
            } else {
                break;
            }
        }
        if (take) {
            nodes.insert(a[i]);
        }
    }
    vector<int> dp(p, 0);
    for (auto& x : nodes) {
        int lg = __lg(x);
        if (lg < p) {
            dp[lg]++;
        }
    }
    for (int i = 0; i < p; ++i) {
        if (i - 1 >= 0) {
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
        }
        if (i - 2 >= 0) {
            dp[i] += dp[i - 2];
            dp[i] %= MOD;
        }
    }
    int ans = 0;
    for (int i = 0; i < p; ++i) {
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans;
}
