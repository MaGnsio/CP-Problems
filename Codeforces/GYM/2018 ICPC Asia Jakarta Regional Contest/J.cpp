/**
 *    author:  MaGnsi0
 *    created: 04.11.2023 18:09:04
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> b(n);
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        b[i] = (int)s[i].size();
    }
    vector<vector<string>> a(n);
    for (int i = 0; i < n; ++i) {
        for (int mask = 1; mask < (1 << b[i]); ++mask) {
            string t = "";
            for (int j = 0; j < b[i]; ++j) {
                if (mask >> j & 1) {
                    t += s[i][j];
                }
            }
            a[i].push_back(t);
        }
        sort(a[i].begin(), a[i].end());
    }
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = vector<int>((1 << b[i]) - 1, -OO);
    }
    for (int j = 0; j < (1 << b[n - 1]) - 1; ++j) {
        dp[n - 1][j] = a[n - 1][j].size();
    }
    for (int j = (1 << b[n - 1]) - 3; j >= 0; --j) {
        dp[n - 1][j] = max(dp[n - 1][j], dp[n - 1][j + 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < (1 << b[i]) - 1; ++j) {
            int low = 0, high = (1 << b[i + 1]) - 2, k = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[i][j] < a[i + 1][mid]) {
                    k = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (k == -1) { continue; }
            dp[i][j] = dp[i + 1][k] + a[i][j].size();
        }
        for (int j = (1 << b[i]) - 3; j >= 0; --j) {
            dp[i][j] = max(dp[i][j], dp[i][j + 1]);
        }
    }
    int ans = max(dp[0][0], -1);
    cout << ans;
}
