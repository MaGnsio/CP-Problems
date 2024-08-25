/**
 *    author:  MaGnsi0
 *    created: 25.08.2024 17:36:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        cout << (s[0] == s[n - 1] ? "NO" : "YES") << "\n";
    }
}
