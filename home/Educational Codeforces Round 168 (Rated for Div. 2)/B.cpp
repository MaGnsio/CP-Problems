/**
 *    author:  MaGnsi0
 *    created: 30.07.2024 17:41:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int m; cin >> m;
        vector<string> a(2);
        cin >> a[0] >> a[1];
        int ans = 0;
        for (int j = 1; j + 1 < m; ++j) {
            if (a[0][j] == '.' && a[1][j + 1] == 'x' && a[1][j - 1] == 'x'
             && a[1][j] == '.' && a[0][j + 1] == '.' && a[0][j - 1] == '.') {
                ans++;
            }
            if (a[1][j] == '.' && a[0][j + 1] == 'x' && a[0][j - 1] == 'x'
             && a[0][j] == '.' && a[1][j + 1] == '.' && a[1][j - 1] == '.') {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
