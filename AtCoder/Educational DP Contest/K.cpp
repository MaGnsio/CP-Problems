/**
 *    author:  MaGnsi0
 *    created: 29/07/2021 19:42:30
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> dp(k + 1, 0);
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < v[j]) {
                continue;
            }
            dp[i] = (!dp[i - v[j]] || dp[i]);
        }
    }
    cout << (dp[k] ? "First" : "Second");
}
