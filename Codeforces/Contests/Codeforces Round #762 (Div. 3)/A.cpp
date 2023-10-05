/**
 *    author:  MaGnsi0
 *    created: 05.01.2022 21:24:42
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
        if ((int)s.size() & 1) {
            cout << "NO\n";
            continue;
        }
        cout << (s.substr(0, (int)s.size() / 2) == s.substr((int)s.size() / 2) ? "YES\n" : "NO\n");
    }
}
