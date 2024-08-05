/**
 *    author:  MaGnsi0
 *    created: 07.07.2024 17:40:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            string in; cin >> in;
            for (int j = 0; j < m; ++j) {
                a[i][j] = in[j] - '0';
            }
        }
        for (int i = 0; i < n; ++i) {
            string in; cin >> in;
            for (int j = 0; j < m; ++j) {
                b[i][j] = in[j] - '0';
            }
        }
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j + 1 < m; ++j) {
                if (a[i][j] == b[i][j]) { continue; }
                if ((a[i][j] + 1) % 3 == b[i][j]) {
                    a[i][j] = (a[i][j] + 1) % 3;
                    a[i][j + 1] = (a[i][j + 1] + 2) % 3;
                    a[i + 1][j] = (a[i + 1][j] + 2) % 3;
                    a[i + 1][j + 1] = (a[i + 1][j + 1] + 1) % 3;
                } else {
                    a[i][j] = (a[i][j] + 2) % 3;
                    a[i][j + 1] = (a[i][j + 1] + 1) % 3;
                    a[i + 1][j] = (a[i + 1][j] + 1) % 3;
                    a[i + 1][j + 1] = (a[i + 1][j + 1] + 2) % 3;
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ok = ok && a[i][j] == b[i][j];
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
