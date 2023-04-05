/**
 *    author:  MaGnsi0
 *    created: 28.02.2023 16:43:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        if (s[0] == t[0]) {
            cout << "YES\n";
            cout << s[0] << "*\n";
            continue;
        }
        if (s[n - 1] == t[m - 1]) {
            cout << "YES\n";
            cout << "*" << s[n - 1] << "\n";
            continue;
        }
        string ans = "";
        for (int i = 0; i + 1 < n; ++i) {
            string x = "";
            x += s[i], x += s[i + 1];
            for (int j = 0; j + 1 < m; ++j) {
                string y = "";
                y += t[j], y += t[j + 1];
                if (x == y) {
                    ans = "";
                    ans += "*";
                    ans += x;
                    ans += "*";
                }
            }
        }
        if (!ans.empty()) {
            cout << "YES\n";
            cout << ans << "\n";
            continue;
        }
        cout << "NO\n";
    }
}
