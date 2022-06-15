/**
 *    author:  MaGnsi0
 *    created: 11.03.2022 22:10:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cipher.in", "r", stdin);
    string s, t;
    getline(cin, s);
    getline(cin, t);
    string ans = "";
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == ' ') {
            assert(t[i] == ' ');
            continue;
        }
        ans += char('a' + (s[i] - t[i] < 0 ? 26 + (s[i] - t[i]) : s[i] - t[i]));
    }
    for (int i = 1; i <= (int)ans.size(); ++i) {
        string k = ans.substr(0, i);
        bool ok = true;
        for (int j = i; j <= (int)ans.size(); j += i) {
            if (j + i - 1 >= (int)ans.size()) {
                string b = ans.substr(j);
                for (int ii = 0; ii < (int)b.size(); ++ii) {
                    ok = (ok && (k[ii] == b[ii]));
                }
            } else {
                string b = ans.substr(j, i);
                ok = (ok && (k == b));
            }
        }
        if (ok) {
            cout << k;
            return 0;
        }
    }
}
