/**
 *    author:  MaGnsi0
 *    created: 09.02.2025 16:37:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int)s.size(), ans = n;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                ans = 1; break;
            }
        }
        cout << ans << "\n";
    }
}
