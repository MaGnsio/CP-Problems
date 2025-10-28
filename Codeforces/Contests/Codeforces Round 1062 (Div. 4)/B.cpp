/**
 *    author:  MaGnsi0
 *    created: 28.10.2025 17:37:52
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
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        cout << (s == t ? "YES" : "NO") << "\n";
    }
}
