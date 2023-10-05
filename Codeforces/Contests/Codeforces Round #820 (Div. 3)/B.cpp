/**
 *    author:  MaGnsi0
 *    created: 12.09.2022 16:33:15
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
        string ans = "";
        for (int i = 0; i < n; ++i) {
            if (i + 2 < n && s[i + 2] == '0' && (i + 3 >= n || s[i + 3] != '0')) {
                ans += char('a' + stoi(s.substr(i, 2)) - 1);
                i += 2;
            } else {
                ans += char('a' + s[i] - '0' - 1);
            }
        }
        cout << ans << "\n";
    }
}
