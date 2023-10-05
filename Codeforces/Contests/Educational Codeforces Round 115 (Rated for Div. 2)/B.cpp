/**
 *    author:  MaGnsi0
 *    created: 11.10.2021 22:55:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(5));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> a[i][j];
            }
        }
        bool ok = false;
        for (int i = 0; i < 5; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                int x = 0, y = 0;
                bool bad = false;
                for (int k = 0; k < n; ++k) {
                    if (a[k][i] && a[k][j]) {
                        continue;
                    } else if (a[k][i]) {
                        x++;
                    } else if (a[k][j]) {
                        y++;
                    } else {
                        bad = true;
                    }
                }
                if (bad || x > n / 2 || y > n / 2) {
                    continue;
                }
                ok = true;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
