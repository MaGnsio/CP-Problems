/**
 *    author:  MaGnsi0
 *    created: 28.02.2023 16:37:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s = "";
    for (int i = 1; i <= 100; ++i) {
        if (i % 3 == 0) { s += 'F'; }
        if (i % 5 == 0) { s += 'B'; }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string t;
        cin >> t;
        bool ok = false;
        for (int i = 0; i + n - 1 < s.size(); ++i) {
            ok |= t == s.substr(i, n);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
