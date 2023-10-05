/**
 *    author:  MaGnsi0
 *    created: 11.10.2022 16:36:34
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
        if (s == t) {
            cout << "=\n";
        } else if (s.back() == t.back()) {
            if (s.back() == 'L') {
                cout << ((int)s.size() > (int)t.size() ? ">" : "<") << "\n";
            } else {
                cout << ((int)s.size() > (int)t.size() ? "<" : ">") << "\n";
            }
        } else {
            if (s.back() == 'L') {
                cout << ">" << "\n";
            } else if (s.back() == 'M' && t.back() == 'S') {
                cout << ">" << "\n";
            } else {
                cout << "<" << "\n";
            }
        }
    }
}
