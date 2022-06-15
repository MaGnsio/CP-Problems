/**
 *    author:  MaGnsi0
 *    created: 16.05.2022 23:50:00
**/
#include <bits/stdc++.h>

using namespace std;

int64_t solve(int c, vector<pair<int, int>> a) {
    int n = (int)a.size();
    sort(a.begin(), a.end());
    vector<int64_t> zeros(n, 0), ones(n, 0), cnt(n, 0);
    for (int i = 1; i < n; ++i) {
        zeros[i] = zeros[i - 1];
        ones[i] = ones[i - 1];
        cnt[i] = cnt[i - 1];
        if (a[i].second == 0) {
            zeros[i] += (int64_t)a[i].first;
            cnt[i]++;
        } else {
            ones[i] += (int64_t)a[i].first;
            cnt[i]--;
        }
    }
    if (n == 1) {
        return int64_t(0);
    }
    vector<int64_t> dp(n, 0);
    map<int, int> mp;
    dp[0] = 0, dp[1] = a[1].first;
    mp[0] = 0, mp[cnt[1]] = 1;
    for (int i = 2; i < n; ++i) {
        if (a[i].second != a[i - 1].second) {
            dp[i] = dp[i - 2] + a[i].first;
        } else {
            dp[i] = dp[i - 2] + a[i].first + c;
            dp[i] = min(dp[i], dp[mp[cnt[i]]] + (a[i].second == 0 ? zeros[i] - zeros[mp[cnt[i]]] : ones[i] - ones[mp[cnt[i]]])); 
        }
        mp[cnt[i]] = i;
    }
    return dp[n - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, c;
        cin >> n >> c;
        vector<pair<int, int>> pos(1, {0, 0}), neg(1, {0, 0});
        for (int i = 0; i < n; ++i) {
            int x, s;
            cin >> x >> s;
            if (x > 0) {
                pos.push_back(make_pair(2 * x, s));
            } else {
                neg.push_back(make_pair(-2 * x, s));
            }
        }
        int64_t ans = solve(c, pos) + solve(c, neg);
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
