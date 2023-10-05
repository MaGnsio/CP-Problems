/**
 *    author:  MaGnsi0
 *    created: 06.01.2022 22:39:59
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
        vector<vector<int>> a(2 * n, vector<int>(2 * n));
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < 2 * n; ++j) {
                cin >> a[i][j];
            }
        }
        long long res = 0;
        for (int i = n; i < 2 * n; ++i) {
            for (int j = n; j < 2 * n; ++j) {
                res += a[i][j];
            }
        }
        int minimum_entrance = INT_MAX;
        minimum_entrance = min(minimum_entrance, a[0][n]);
        minimum_entrance = min(minimum_entrance, a[0][2 * n - 1]);
        minimum_entrance = min(minimum_entrance, a[n - 1][n]);
        minimum_entrance = min(minimum_entrance, a[n - 1][2 * n - 1]);
        minimum_entrance = min(minimum_entrance, a[n][0]);
        minimum_entrance = min(minimum_entrance, a[n][n - 1]);
        minimum_entrance = min(minimum_entrance, a[2 * n - 1][0]);
        minimum_entrance = min(minimum_entrance, a[2 * n - 1][n - 1]);
        cout << res + minimum_entrance << "\n";
    }
}
