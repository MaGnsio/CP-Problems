/**
 *    author:  MaGnsi0
 *    created: 13.04.2024 02:31:04
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
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) { continue; }
            if (s[i] < t[i]) { swap(s[i], t[i]); }
            for (int j = i + 1; j < n; ++j) {
                if (s[j] > t[j]) { swap(s[j], t[j]); }
            }
            break;
        }
        cout << s << "\n";
        cout << t << "\n";
    }
}
