/**
 *    author:  MaGnsi0
 *    created: 12.02.2022 16:29:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int s = accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0); 
        vector<bool> dp(s + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = s; j >= 0; --j) {
                if (dp[j]) {
                    if (j + a[i] <= s) {
                        dp[j + a[i]] = true;
                    }
                    if (j + b[i] <= s) {
                        dp[j + b[i]] = true;
                    }
                    dp[j] = false;
                }
            }
        }
        int s1 = 0;
        for (int i = 0; i <= s; ++i) {
            if (!dp[i]) {
                continue;
            }
            if (abs(i - (s - i)) < abs(s1 - (s - s1))) {
                s1 = i;
            }
        }
        int x = 0;
        for (int i = 0; i < n; ++i) {
            x += (a[i] * a[i]) + (b[i] * b[i]);
        }
        int res = (n - 2) * x + s1 * s1 + (s - s1) * (s - s1);
        cout << res << "\n";
    }
}
