/**
 *    author:  MaGnsi0
 *    created: 06.11.2022 16:39:19
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
        int64_t x = count(s.begin(), s.end(), '1');
        int64_t y = count(s.begin(), s.end(), '0');
        int64_t ans = x * y;
        int64_t cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                ans = max(ans, cnt * cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt * cnt);
        cout << ans << "\n";
    }
}
