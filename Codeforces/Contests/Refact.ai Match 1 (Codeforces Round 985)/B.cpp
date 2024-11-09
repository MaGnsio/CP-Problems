/**
 *    author:  MaGnsi0
 *    created: 09.11.2024 23:06:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        string t; cin >> t;
        int o = count(s.begin(), s.end(), '1');
        int z = count(s.begin(), s.end(), '0');
        bool ok = true;
        for (int i = 0; i < n - 1; ++i) {
            ok = ok && o && z;
            o -= t[i] == '0';
            z -= t[i] == '1';
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
