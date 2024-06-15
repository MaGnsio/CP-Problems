/**
 *    author:  MaGnsi0
 *    created: 06.06.2024 15:49:14
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
        int ans = 0;
        for (int i = 0; i < 7; ++i) {
            ans += max(m - int(count(s.begin(), s.end(), char('A' + i))), 0);
        }
        cout << ans << "\n";
    }
}
