/**
 *    author:  MaGnsi0
 *    created: 30.11.2024 16:39:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int k; cin >> k;
        string s; cin >> s;
        int ans = 0;
        for (int i = 0, z = 0; i < n; ++i) {
            if (s[i] == '0') {
                z++;
            } else {
                z = 0;
            }
            if (z == m) {
                z = 0, i += k - 1, ans++;
            }
        }
        cout << ans << "\n";
    }
}
