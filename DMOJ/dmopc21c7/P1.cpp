/**
 *    author:  MaGnsi0
 *    created: 17.04.2023 22:21:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int64_t>> a(n, vector<int64_t>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    if (a[0][0] == 0) { a[0][0] = 1; }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j]) { continue; }
            int64_t x = (i ? a[i - 1][j] : 0);
            int64_t y = (j ? a[i][j - 1] : 0);
            a[i][j] = max(x, y) + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int64_t x = (i ? a[i - 1][j] : 0);
            int64_t y = (j ? a[i][j - 1] : 0);
            if (a[i][j] <= x || a[i][j] <= y) {
                cout << -1;
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
