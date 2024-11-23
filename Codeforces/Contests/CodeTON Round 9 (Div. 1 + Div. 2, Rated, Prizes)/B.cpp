/**
 *    author:  MaGnsi0
 *    created: 23.11.2024 16:40:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int)s.size();
        string ans = "";
        for (int i = 0; i + 2 < n; ++i) {
            if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i + 2] != s[i]) {
                ans = s.substr(i, 3);
            }
        }
        for (int i = 0; i + 1 < n; ++i) {
            if (s[i] == s[i + 1]) {
                ans = s.substr(i, 2);
            }
        }
        if (ans == "") {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
}
