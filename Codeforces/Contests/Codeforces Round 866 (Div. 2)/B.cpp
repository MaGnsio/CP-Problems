/**
 *    author:  MaGnsi0
 *    created: 04.05.2023 17:55:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int64_t n = (int)s.size();
        if (count(s.begin(), s.end(), '1') == n) {
            cout << n * n << "\n";
            continue;
        }
        s += s;
        n *= 2;
        int64_t maxo = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                maxo = max(maxo, cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        maxo = max(maxo, cnt);
        int64_t ans = maxo;
        for (int i = 1; i < maxo; ++i) {
            ans = max(ans, (maxo - i) * (i + 1));
        }
        cout << ans << "\n";
    }
}
