/**
 *    author:  MaGnsi0
 *    created: 03.03.2022 17:21:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }
    if (n > m) {
        cout << "YES\n";
    } else {
        vector<bool> dp(m, false);
        for (int i = 0; i < n; ++i) {
            vector<bool> temp = dp;
            temp[a[i]] = true;
            for (int j = 0; j < m; ++j) {
                if (dp[j]) {
                    temp[(a[i] + j) % m] = true;
                }
            }
            dp = temp;
        }
        cout << (dp[0] ? "YES" : "NO");
    }
}
