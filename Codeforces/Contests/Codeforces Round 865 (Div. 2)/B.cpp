/**
 *    author:  MaGnsi0
 *    created: 09.04.2023 17:04:18
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
        vector<vector<int>> a(2, vector<int>(n));
        for (int i = 0; i < 2; ++i) {
            int m = 2 * n - i;
            for (int j = i; j < n; j += 2) {
                a[i][j] = m;
                m -= 2;
            }
        }
        for (int i = 0; i < 2; ++i) {
            int m = 1 + (i ^ 1);
            for (int j = i ^ 1; j < n; j += 2) {
                a[i][j] = m;
                m += 2;
            }
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 2 * n - 1) {
                    swap(a[i][j], a[1][n - 1]);
                }
            }
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
