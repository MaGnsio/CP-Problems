/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 16:29:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        string t = "codeforces";
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            ans += s[i] != t[i];
        }
        cout << ans << "\n";
    }
}
