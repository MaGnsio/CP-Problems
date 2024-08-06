/**
 *    author:  MaGnsi0
 *    created: 06.08.2024 18:05:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        string t; cin >> t;
        int i = 0, j = 0;
        while (i < (int)s.size() && j < (int)t.size()) {
            if (s[i] == '?') {
                s[i] = t[j];
            }
            j += s[i] == t[j]; i++;
        }
        while (i < (int)s.size()) {
            s[i] = (s[i] == '?' ? 'x' : s[i]); i++;
        }
        if (j == (int)t.size()) {
            cout << "YES\n" << s << "\n";
        } else {
            cout << "NO\n";
        }
    }
}
