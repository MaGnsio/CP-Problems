/**
 *    author:  MaGnsi0
 *    created: 14.10.2024 17:36:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        string t; cin >> t;
        int n = (int)s.size();
        int m = (int)t.size();
        int ans = n + m, common = 0;
        for (int i = 0; i < min(n, m); ++i) {
            if (s[i] != t[i]) { break; }
            common++;
        }
        ans = ans - (common ? common - 1 : 0);
        cout << ans << "\n";
    }
}
