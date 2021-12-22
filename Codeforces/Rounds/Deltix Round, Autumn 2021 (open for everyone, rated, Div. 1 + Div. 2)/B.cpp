/**
 *    author:  MaGnsi0
 *    created: 28.11.2021 16:27:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    string s;
    cin >> n >> q >> s;
    int res = 0;
    for (int i = 0; i + 2 < n; ++i) {
        res += (s.substr(i, 3) == "abc");
    }
    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        if (s[pos] == c) {
            cout << res << "\n";
            continue;
        }
        for (int i = max(pos - 2, 0); i <= pos && i + 2 < n; ++i) {
            res -= (s.substr(i, 3) == "abc");
        }
        s[pos] = c;
        for (int i = max(pos - 2, 0); i <= pos && i + 2 < n; ++i) {
            res += (s.substr(i, 3) == "abc");
        }
        cout << res << "\n";
    }
}
