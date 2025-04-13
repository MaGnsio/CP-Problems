/**
 *    author:  MaGnsi0
 *    created: 13.04.2025 20:27:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        string t; cin >> t;
        int n = (int)s.size();
        int m = (int)t.size();
        string su = "", tu = "";
        su += s[0]; tu += t[0];
        vector<int> sc(1, 1), tc(1, 1);
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) {
                su += s[i]; sc.push_back(1);
            } else {
                sc.back()++;
            }
        }
        for (int i = 1; i < m; ++i) {
            if (t[i] != t[i - 1]) {
                tu += t[i]; tc.push_back(1);
            } else {
                tc.back()++;
            }
        }
        if (su != tu) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        for (int i = 0; i < (int)sc.size(); ++i) {
            ok = ok && sc[i] <= tc[i] && tc[i] <= 2 * sc[i];
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
