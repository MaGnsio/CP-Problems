/**
 *    author:  MaGnsi0
 *    created: 30.08.2022 16:34:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            ok &= ((s[i] == t[i]) || (s[i] == 'G' && t[i] == 'B') || (s[i] == 'B' && t[i] == 'G'));
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
