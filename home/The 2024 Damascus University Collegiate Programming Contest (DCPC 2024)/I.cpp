/**
 *    author:  MaGnsi0
 *    created: 16.07.2024 22:08:28
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 21, OO = 1 << 23;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> f(1 << M);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; f[x]++;
    }
    vector<vector<pair<int, int>>> dp(1 << M, vector<pair<int, int>>(M + 1, {OO, OO}));
    for (int mask = 1; mask < (1 << M); ++mask) {
        if (f[mask] == 1) {
            dp[mask][0] = make_pair(OO, mask);
        } else if (f[mask] > 1) {
            dp[mask][0] = make_pair(0, OO);
        }
        for (int x = 1; x <= M; ++x) {
            int b = x - 1;
            pair<int, int>& res = dp[mask][x];
            if (mask >> b & 1) {
                pair<int, int> res1 = dp[mask][x - 1];
                pair<int, int> res2 = dp[mask ^ (1 << b)][x - 1];
                res = min(res1, res2);
                if (res1.second != OO && res2.second != OO) {
                    res = min(res, make_pair(res1.second ^ res2.second, OO));
                }
            } else {
                res = min(res, dp[mask][x - 1]);
            }
        }
    }
    int Q; cin >> Q;
    while (Q--) {
        int x; cin >> x;
        int ans = dp[x][M].first;
        cout << (ans == OO ? -1 : ans) << "\n";
    }
}
