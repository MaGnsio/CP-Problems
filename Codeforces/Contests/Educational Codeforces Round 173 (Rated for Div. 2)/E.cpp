/**
 *    author:  MaGnsi0
 *    created: 24.12.2024 18:00:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector a(n, vector<int64_t>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        vector b(n, vector<int64_t>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
            }
        }
        for (int t = 0; t < n * m; ++t) {
            for (int i = 0; i < n; ++i) {
                int x = 0;
                for (int j = 0; j < m; ++j) {
                    x |= (a[i][j] & (~b[i][j]));
                }
                for (int j = 0; j < m; ++j) {
                    a[i][j] &= ~x;
                }
            }
            for (int j = 0; j < m; ++j) {
                int x = 0;
                for (int i = 0; i < n; ++i) {
                    x |= ((~a[i][j]) & (b[i][j]));
                }
                for (int i = 0; i < n; ++i) {
                    a[i][j] |= x;
                }
            }
        }
        cout << (a == b ? "YES" : "NO") << "\n";
    }
}

