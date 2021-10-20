/**
 *    author:  MaGnsi0
 *    created: 30/07/2021 01:52:25
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int e, z, p, c;
        for (int i = 0; i < 26; ++i) {
            if (s[i] == 'e') {
                e = i;
            }
            if (s[i] == 'z') {
                z = i;
            }
            if (s[i] == 'p') {
                p = i;
            }
            if (s[i] == 'c') {
                c = i;
            }
        }
        if (c < e || p < z || c < z || c < p) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
