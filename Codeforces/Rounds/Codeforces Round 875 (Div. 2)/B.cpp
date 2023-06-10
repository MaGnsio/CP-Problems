/**
 *    author:  MaGnsi0
 *    created: 28.05.2023 17:50:37
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            b[i]--;
        }
        vector<vector<int>> c(2, vector<int>(2 * n, 0));
        for (int i = 0; i < n; ) {
            int x = 1, y = a[i];
            for (int j = i + 1; j < n; ++j) {
                if (a[j] != a[i]) {
                    i = j;
                    break;
                } else {
                    x++;
                }
                if (j == n - 1) { i = n; }
            }
            if (a[i] == y) { i++; }
            c[0][y] = max(c[0][y], x);
        }
        for (int i = 0; i < n; ) {
            int x = 1, y = b[i];
            for (int j = i + 1; j < n; ++j) {
                if (b[j] != b[i]) {
                    i = j;
                    break;
                } else {
                    x++;
                }
                if (j == n - 1) { i = n; }
            }
            if (b[i] == y) { i++; }
            c[1][y] = max(c[1][y], x);
        }
        int ans = 0;
        for (int i = 0; i < 2 * n; ++i) {
            ans = max(ans, c[0][i] + c[1][i]);
        }
        cout << ans << "\n";
    }
}
