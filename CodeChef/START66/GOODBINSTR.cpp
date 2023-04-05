/**
 *    author:  MaGnsi0
 *    created: 23.11.2022 16:33:52
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
        int x = 0, y = 0;
        for (int i = 0; i < (int)s.size() - 1; ++i) {
            x += s[i] == '0' && s[i + 1] == '1';
            y += s[i] == '1' && s[i + 1] == '0';
        }
        int ans = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (i + 1 < (int)s.size()) {
                x -= s[i] == '0' && s[i + 1] == '1';
                y -= s[i] == '1' && s[i + 1] == '0';
                x += s[i] == '1' && s[i + 1] == '1';
                y += s[i] == '0' && s[i + 1] == '0';
            }
            if (i) {
                x -= s[i - 1] == '0' && s[i] == '1';
                y -= s[i - 1] == '1' && s[i] == '0';
                x += s[i - 1] == '0' && s[i] == '0';
                y += s[i - 1] == '1' && s[i] == '1';
            }
            ans += x == y;
            if (i + 1 < (int)s.size()) {
                x += s[i] == '0' && s[i + 1] == '1';
                y += s[i] == '1' && s[i + 1] == '0';
                x -= s[i] == '1' && s[i + 1] == '1';
                y -= s[i] == '0' && s[i + 1] == '0';
            }
            if (i) {
                x += s[i - 1] == '0' && s[i] == '1';
                y += s[i - 1] == '1' && s[i] == '0';
                x -= s[i - 1] == '0' && s[i] == '0';
                y -= s[i - 1] == '1' && s[i] == '1';
            }
        }
        cout << ans << "\n";
    }
}
