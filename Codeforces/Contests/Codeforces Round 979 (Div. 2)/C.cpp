/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 17:15:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        if (s[0] == '1' || s[n - 1] == '1') {
            cout << "YES\n";
            continue;
        }
        bool ok = false;
        for (int i = 0; i + 1 < n; ++i) {
            ok |= s[i] == '1' && s[i + 1] == '1';
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
