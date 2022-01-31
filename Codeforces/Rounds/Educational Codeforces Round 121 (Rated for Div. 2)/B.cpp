/**
 *    author:  MaGnsi0
 *    created: 20.01.2022 16:22:24
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
        string res = s;
        res.erase(0, 2);
        res.insert(res.begin(), char(s[0] + s[1] - '0'));
        for (int i = (int)s.size() - 2; i >= 0; --i) {
            if (s[i] + s[i + 1] - 2 * '0' > 9) {
                res = s;
                res.erase(i, 2);
                res.insert(i, to_string(s[i] + s[i + 1] - 2 * '0'));
                break;
            }
        }
        cout << res << "\n";
    }
}
