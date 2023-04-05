/**
 *    author:  MaGnsi0
 *    created: 11.02.2023 14:15:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int x;
    cin >> x;
    vector<bool> trap(x, false);
    for (int i = 0; i < m; ++i) {
        trap[b[i]] = true;
    }
    vector<bool> dp(x + 1, false);
    dp[0] = true;
    for (int j = 0; j <= x; ++j) {
        if (!dp[j] || trap[j]) { continue; }
        for (int i = 0; i < n; ++i) {
            if (j + a[i] <= x) {
                dp[j + a[i]] = true;
            }
        }
    }
    cout << (dp[x] ? "Yes" : "No");
}
