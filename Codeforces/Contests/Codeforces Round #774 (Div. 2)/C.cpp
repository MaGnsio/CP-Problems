/**
 *    author:  MaGnsi0
 *    created: 05.03.2022 19:29:35
**/
#include <bits/stdc++.h>

using namespace std;

const long long N = 1e12 + 12;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<long long> powerful;
    for (long long i = 1, j = 1; i <= N; ++j, i *= j) {
        powerful.push_back(i);
    }
    map<long long, int> dp;
    for (int i = 0; i < (int)powerful.size(); ++i) {
        map<long long, int> temp = dp;
        temp[powerful[i]] = 1;
        for (auto& [x, y] : dp) {
            if (powerful[i] + x > N) {
                continue;
            }
            if (dp.count(powerful[i] + x)) {
                temp[powerful[i] + x] = min(dp[powerful[i] + x], y + 1);
            } else {
                temp[powerful[i] + x] = y + 1;
            }
        }
        dp = temp;
    }
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        int ans = __builtin_popcountll(n);
        for (auto& [x, y] : dp) {
            if (x <= n && n - x != x) {
                ans = min(ans, __builtin_popcountll(n - x) + y);
            }
        }
        cout << ans << "\n";
    }
}
