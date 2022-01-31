/**
 *    author:  MaGnsi0
 *    created: 01.01.2022 22:26:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= 0; --j) {
            if (j - a[i] >= 0) {
                dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
        }
    }
    cout << dp[x];
}
