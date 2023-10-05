/**
 *    author:  MaGnsi0
 *    created: 19.02.2022 19:23:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = (i & 1); j < m; j += 2) {
                a[i][j] += (a[i][j] & 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = !(i & 1); j < m; j += 2) {
                a[i][j] += !(a[i][j] & 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
