/**
 *    author:  MaGnsi0
 *    created: 19.12.2021 16:53:58
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n + 1, OO);
    dp[n] = 0;
    for (int i = n; i >= 0; --i) {
        int x = i;
        vector<int> a;
        while (x) {
            if (x % 10) {
                a.push_back(x % 10);
            }
            x /= 10;
        }
        for (int j = 0; j < (int)a.size(); ++j) {
            dp[i - a[j]] = min(dp[i - a[j]], dp[i] + 1);
        }
    }
    cout << dp[0];
}
