/**
 *    author:  MaGnsi0
 *    created: 06.01.2022 18:17:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //O(3^n) solution doesn't work only O(2^n * n) does.
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> dp(1 << n, {n + 1, 0});
    dp[0] = {1, 0};
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                pair<int, int> best = dp[i ^ (1 << j)];
                if (best.second + a[j] <= x) {
                    best.second += a[j];
                } else {
                    best.first++;
                    best.second = a[j];
                }
                dp[i] = min(dp[i], best);
            }
        }
    }
    cout << dp[(1 << n) - 1].first;
}
