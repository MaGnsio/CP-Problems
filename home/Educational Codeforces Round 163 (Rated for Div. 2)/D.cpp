/**
 *    author:  MaGnsi0
 *    created: 29.05.2024 22:09:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s; string t = s;
        reverse(t.begin(), t.end());
        int ans = 0, n = (int)s.size();
        for (int m = 1; m <= n / 2; ++m) {
            for (int i = 0, good = 0; i + m < n; ++i) {
                if (s[i] == s[i + m] || s[i] == '?' || s[i + m] == '?') {
                    good++;
                } else {
                    good = 0;
                }
                if (good == m) {
                    ans = max(ans, 2 * m);
                }
            }
        }
        cout << ans << "\n";
    }
}
