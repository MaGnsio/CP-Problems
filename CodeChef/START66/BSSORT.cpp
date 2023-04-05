/**
 *    author:  MaGnsi0
 *    created: 23.11.2022 18:12:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> ends(n, 0);
        ends[n - 1] = s[n - 1] == '1';
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '1') {
                ends[i] = ends[i + 1] + 1;
            } else {
                ends[i] = 0;
            }
        }
        int last_one = (s[n - 1] == '1' ? n - 1 : -1);
        vector<int64_t> dp(n, 0);
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = dp[i + 1] + 1;
            } else {
                if (last_one == -1) {
                    dp[i] = dp[i + 1] + 1;
                } else {
                    int j = last_one + ends[last_one];
                    if (j >= n) {
                        j = n - 1;
                    } else {
                        assert(s[j] == '0');
                        if (j + 1 >= n || s[j + 1] == '0') {
                            //do nothing
                        } else {
                            j = j + ends[j + 1];
                        }
                    }
                    dp[i] = j - i + 1;
                }
                last_one = i;
            }
        }
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dp[i];
        }
        cout << ans << "\n";
    }
}
