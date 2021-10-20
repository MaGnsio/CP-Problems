/**
 *    author:  MaGnsi0
 *    created: 22/07/2021 16:43:13
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        bool ok = false;
        for (int i = 0; i < s.size(); ++i) {
            string x = "";
            for (int j = i; j < s.size(); ++j) {
                if (x.size() > t.size()) {
                    break;
                }
                x += s[j];
                if (x == t) {
                    ok = true;
                    goto chk;
                }
                string y = x;
                for (int k = j - 1; k >= 0; --k) {
                    if (y.size() > t.size()) {
                        break;
                    }
                    y += s[k];
                    if (y == t) {
                        ok = true;
                        goto chk;
                    }
                }
            }
        }
        chk:
        cout << (ok ? "YES\n" : "NO\n");
    }
}
