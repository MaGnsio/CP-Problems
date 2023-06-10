/**
 *    author:  MaGnsi0
 *    created: 04.05.2023 17:37:55
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
        int ans = (s[0] == '_') + (s.back() == '_');
        for (int i = 0; i + 1 < (int)s.size(); ++i) {
            ans += (s[i] == s[i + 1]) && (s[i] == '_');
        }
        if ((int)s.size() == 1 && s[0] == '^') { ans++; }
        cout << ans << "\n";
    }
}
