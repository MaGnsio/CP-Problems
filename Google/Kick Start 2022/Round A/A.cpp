/**
 *    author:  MaGnsi0
 *    created: 20.03.2022 06:01:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s, k;
        cin >> s >> k;
        bool can = true;
        for (int i = 0, j = 0; i < (int)s.size(); ++i) {
            bool ok = false;
            for (; j < (int)k.size(); ++j) {
                if (s[i] == k[j]) {
                    ok = true;
                    j++;
                    break;
                }
            }
            can = (can && ok);
        }
        cout << "Case #" << t << ": ";
        if (can) {
            cout << (int)k.size() - (int)s.size() << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
}
