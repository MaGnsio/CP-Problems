/**
 *    author:  MaGnsi0
 *    created: 08.04.2023 16:14:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        if (n == 1) {
            cout << "YES\n";
            continue;
        }
        bool ok = true, have_ident = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                have_ident |= (i == n - i - 1 && j == n - j - 1);
                if (a[i][j] != a[n - i - 1][n - j - 1]) {
                    a[i][j] = a[n - i - 1][n - j - 1] = 0;
                    if (k) {
                        k--;
                    } else {
                        ok = false;
                    }
                }
            }
        }
        cout << (ok && ((k % 2 == 0) || have_ident) ? "YES" : "NO") << "\n";
    }
}
