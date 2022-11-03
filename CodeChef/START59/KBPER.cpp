/**
 *    author:  MaGnsi0
 *    created: 05.10.2022 18:18:58
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int m = (n + 1) / 2, x = n / 2;
        for (int i = 0; i < n; ++i) {
            m -= a[i] % 2;
            x -= (a[i] && a[i] % 2 == 0);
        }
        vector<int> b(n, 0);
        for (int i = 0; i < n; ++i) {
            b[i] = a[i] == 0;
        }
        for (int i = 1; i < n; ++i) {
            b[i] += b[i - 1];
        }
        vector<vector<vector<vector<int64_t>>>> dp(n, vector<vector<vector<int64_t>>>(k + 1, vector<vector<int64_t>>(m + 1, vector<int64_t>(3, -1))));
        function<int64_t(int, int, int, int)> solve = [&](int j, int cur_k, int odd, int cur_segment) {
            if (j == n) {
                assert(odd == 0);
                return int64_t(cur_k == k);
            }
            if (cur_k > k) {
                return int64_t(0);
            }
            int64_t& ans = dp[j][cur_k][odd][cur_segment];
            if (ans != -1) {
                return ans;
            }
            ans = 0;
            if (a[j] != 0) {
                if (a[j] & 1) {
                    ans += solve(j + 1, cur_k + (cur_segment != 1), odd, 1);
                    ans %= MOD;
                } else {
                    ans += solve(j + 1, cur_k + (cur_segment != 2), odd, 2);
                    ans %= MOD;
                }
            } else {
                int even = x - ((j ? b[j - 1] : 0) - m + odd);
                if (cur_segment == 0) {
                    if (odd > 0) {
                        ans += odd * solve(j + 1, cur_k + 1, odd - 1, 1);
                        ans %= MOD;
                    }
                    if (even > 0) {
                        ans += even * solve(j + 1, cur_k + 1, odd, 2);
                        ans %= MOD;
                    }
                } else if (cur_segment == 1) {
                    if (odd > 0) {
                        ans += odd * solve(j + 1, cur_k, odd - 1, 1);
                        ans %= MOD;
                    }
                    if (even > 0) {
                        ans += even * solve(j + 1, cur_k + 1, odd, 2);
                        ans %= MOD;
                    }
                } else {
                    if (odd > 0) {
                        ans += odd * solve(j + 1, cur_k + 1, odd - 1, 1);
                        ans %= MOD;
                    }
                    if (even > 0) {
                        ans += even * solve(j + 1, cur_k, odd, 2);
                        ans %= MOD;
                    }
                }
            }
            return ans;
        };
        cout << solve(0, 0, m, 0) << "\n";
    }
}
