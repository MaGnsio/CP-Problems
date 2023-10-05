/**
 *    author:  MaGnsi0
 *    created: 31.08.2023 18:03:20
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
        bool ok = true;
        int n = (int)s.size();
        int m = 0, r = 0;
        set<int> bad;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '-') {
                assert(m);
                bad.erase(m - 1);
                r = min(r, m - 2);
                m--;
            } else if (s[i] == '+') {
                m++;
            } else if (s[i] == '1') {
                if (!bad.empty()) {
                    ok = false;
                    break;
                } else {
                    r = m - 1;
                }
            } else {
                if (m <= 1 || r == m - 1) {
                    ok = false;
                    break;
                } else if (bad.empty()) {
                    bad.insert(m - 1);
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
