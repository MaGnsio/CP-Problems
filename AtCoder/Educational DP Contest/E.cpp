/**
 *    author:  MaGnsi0
 *    created: 29/07/2021 16:29:14
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e13;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, w, v = 0;
    cin >> n >> w;
    vector<int> wi(n), vi(n);
    for (int i = 0; i < n; ++i) {
        cin >> wi[i] >> vi[i];
        v += vi[i];
    }
    vector<int> dp(v + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        //we have to go backward to handle repetition of an item
        for (int j = v; j >= vi[i]; --j) {
            dp[j] = min(dp[j], dp[j - vi[i]] + wi[i]);
        }
    }
    for (int i = v; i >= 0; --i) {
        if (dp[i] <= w) {
            cout << i;
            return 0;
        }
    }
}
