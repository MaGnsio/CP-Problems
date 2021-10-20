/**
 *    author:  MaGnsi0
 *    created: 21/09/2021 01:22:17
**/
#include <bits/stdc++.h>
using namespace std;

int n, l, c;
vector<int> v;
vector<pair<int, int>> dp;

pair<int, int> solve(int x) {
    if (x == n) {
        return {0, 0};
    }
    if (dp[x].first != -1) {
        return dp[x];
    }
    dp[x] = {INT_MAX, INT_MAX};
    for (int i = x, t = l; i < n; ++i) {
        t -= v[i];
        if (t < 0) {
            break;
        }
        int d = (t == 0 ? 0 : (t <= 10 ? -c : (t - 10) * (t - 10)));
        pair<int, int> nxt = solve(i + 1);
        nxt.first += 1, nxt.second += d;
        dp[x] = min(dp[x], nxt);
    }
    return dp[x];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T = 0;
    while ((cin >> n) && n) {
        cin >> l >> c;
        v = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        dp = vector<pair<int, int>>(n, {-1, -1});
        if (T) {
            cout << "\n";
        }
        cout << "Case " << ++T << ":\n";
        cout << "Minimum number of lectures: " << solve(0).first << "\n";
        cout << "Total dissatisfaction index: " << solve(0).second << "\n";
    }
}
