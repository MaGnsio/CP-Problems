/**
 *    author:  MaGnsi0
 *    created: 01.09.2024 18:40:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int m = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                m = i - 1;
                break;
            }
        }
        int SQ = sqrt(n);
        if (m == n) {
            cout << (n == 4 ? "YES" : "NO") << "\n";
            continue;
        }
        if (m <= 0) {
            cout << "NO\n";
            continue;
        }
        if (m * m != n) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        for (int i = 0, x = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j, ++x) {
                if (i == 0 || i == m - 1 || j == 0 || j == m - 1) {
                    ok = ok && s[x] == '1';
                } else {
                    ok = ok && s[x] == '0';
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
