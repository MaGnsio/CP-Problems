/**
 *    author:  MaGnsi0
 *    created: 05.05.2024 14:02:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        string s; cin >> s;
        string t; cin >> t;
        int ans = 0;
        for (int i = 0, j = 0; j < m && i < n; ++j) {
            if (s[i] == t[j]) {
                i++, ans++;
            }
        }
        cout << ans << "\n";
    }
}
