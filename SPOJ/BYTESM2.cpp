/**
 *    author:  MaGnsi0
 *    created: 03/09/2021 18:47:50
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n + 2, vector<int>(m + 2, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> v[i][j];
            }
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                v[i][j] += max({v[i - 1][j - 1], v[i - 1][j], v[i - 1][j + 1]});
            }
        }
        int res = 0;
        for (int i = 1; i <= m; ++i) {
            res = max(res, v[n][i]);
        }
        cout << res << "\n";
    }
}
