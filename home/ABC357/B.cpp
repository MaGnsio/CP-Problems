/**
 *    author:  MaGnsi0
 *    created: 08.06.2024 15:03:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = (int)s.size(), uppers = 0;
    for (int i = 0; i < n; ++i) {
        uppers += isupper(s[i]) != 0;
    }
    if (uppers > n - uppers) {
        for (int i = 0; i < n; ++i) {
            s[i] = toupper(s[i]);
        }
    } else {
        for (int i = 0; i < n; ++i) {
            s[i] = tolower(s[i]);
        }
    }
    cout << s;
}
