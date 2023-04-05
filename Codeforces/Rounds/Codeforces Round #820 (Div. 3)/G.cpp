/**
 *    author:  MaGnsi0
 *    created: 29.11.2022 21:24:24
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int n = (int)s.size();
        vector<bool> have_t(n, false);
        for (int i = 0; i + (int)t.size() - 1 < n; ++i) {
            have_t[i] = s.substr(i, (int)t.size()) == t;
        }
        if (count(have_t.begin(), have_t.end(), false) == n) {
            cout << 0 << " " << 1 << "\n";
            continue;
        }
        vector<int64_t> dp(n, -1), cnt(n, 0);
        function<int64_t(int)> solve = [&](int x) {
            if (x >= n) {
                return int64_t(0);
            }
            if (dp[x] != -1) {
                return dp[x];
            }
            dp[x] = n;
            if (!have_t[x]) {
                dp[x] = solve(x + 1);
                cnt[x] = (x + 1 < n ? cnt[x + 1] : 1);
            } else {
                for (int i = x; i < x + (int)t.size(); ++i) {
                    int j = i + (int)t.size();
                    if (have_t[i]) {
                        dp[x] = min(dp[x], solve(j) + 1);
                    }
                }
                for (int i = x; i < x + (int)t.size(); ++i) {
                    int j = i + (int)t.size();
                    if (have_t[i]) {
                        if (solve(j) + 1 == dp[x]) {
                            cnt[x] += (j < n ? cnt[j] : 1); 
                            cnt[x] %= MOD;
                        }
                    }
                }
            }
            return dp[x];
        };
        cout << solve(0) << " " << cnt[0] << "\n";
    }
}
