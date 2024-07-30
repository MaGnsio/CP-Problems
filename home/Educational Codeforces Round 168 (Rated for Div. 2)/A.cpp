/**
 *    author:  MaGnsi0
 *    created: 30.07.2024 17:36:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int)s.size();
        bool done = 0;
        for (int i = 0; i < n; ++i) {
            cout << s[i];
            if (i + 1 < n && !done && s[i] == s[i + 1]) {
                cout << (s[i] == 'a' ? 'b' : 'a');
                done = true;
            } else if (i == n - 1 && !done) {
                cout << (s[i] == 'a' ? 'b' : 'a');
            }
        }
        cout << "\n";
    }
}
