/**
 *    author:  MaGnsi0
 *    created: 16.12.2021 15:20:56
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
        sort(s.begin(), s.end());
        if (t != "abc") {
            cout << s << "\n";
        } else if (count(s.begin(), s.end(), 'a') == 0 || count(s.begin(), s.end(), 'b') == 0 || count(s.begin(), s.end(), 'c') == 0) {
            cout << s << "\n";
        } else {
            for (int i = 0; i < count(s.begin(), s.end(), 'a'); ++i) {
                cout << "a";
            }
            for (int i = 0; i < count(s.begin(), s.end(), 'c'); ++i) {
                cout << "c";
            }
            for (int i = 0; i < count(s.begin(), s.end(), 'b'); ++i) {
                cout << "b";
            }
            for (int i = 0; i < (int)s.size(); ++i) {
                if (s[i] != 'a' && s[i] != 'b' && s[i] != 'c') {
                    cout << s[i];
                }
            }
            cout << "\n";
        }
    }
}
