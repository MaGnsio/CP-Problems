/**
 *    author:  MaGnsi0
 *    created: 11.10.2021 22:50:17
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
            ok &= !(s[i] == '1' && t[i] == '1');
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
