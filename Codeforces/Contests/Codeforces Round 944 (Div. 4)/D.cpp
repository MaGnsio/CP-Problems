/**
 *    author:  MaGnsi0
 *    created: 15.05.2024 19:29:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int ans = 1;
        for (int i = 1; i < (int)s.size(); ++i) {
            ans += s[i] != s[i - 1];
        }
        if (ans > 2) {
            cout << ans - 1 << "\n";
        } else if (ans == 2) {
            cout << (s[0] == '0' ? 1 : 2) << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
}
