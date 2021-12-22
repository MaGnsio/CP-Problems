/**
 *    author:  MaGnsi0
 *    created: 19.12.2021 16:26:48
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp(x + 1, OO);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            if (j >= a[i]) {
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
            }
        }
    }
    cout << (dp[x] == OO ? -1 : dp[x]);
}
