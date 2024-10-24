/**
 *    author:  MaGnsi0
 *    created: 24.10.2024 17:47:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector a(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        vector b(n, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (b[i][j]) { continue; }
                int add = 0;
                for (int k = 0; i + k < n && j + k < n; ++k) {
                    add = max(add, -a[i + k][j + k]);
                    b[i + k][j + k] = true;
                }
                ans += add;
            }
        }
        cout << ans << "\n";
    }
}
