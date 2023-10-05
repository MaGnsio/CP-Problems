/**
 *    author:  MaGnsi0
 *    created: 31.08.2023 17:41:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        bool ok = false;
        int n = (int)a.size();
        for (int i = 0; i + 1 < n; ++i) {
            string s = a.substr(i, 2);
            string t = b.substr(i, 2);
            if (s == "01" && t == "01") { ok = true; }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
