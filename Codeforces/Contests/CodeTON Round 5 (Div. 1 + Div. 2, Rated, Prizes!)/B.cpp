/**
 *    author:  MaGnsi0
 *    created: 24.06.2023 17:13:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<vector<int>> a(3, vector<int>(n));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        function<bool(int)> F = [&](int y) {
            for (int i = 0; i <= 30; ++i) {
                if (((y >> i) & 1) && (((x >> i) & 1) == 0)) {
                    return false;
                }
            }
            return true;
        };
        int val = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                if (F(a[i][j])) {
                    val |= a[i][j];
                } else {
                    break;
                }
            }
        }
        cout << (val == x ? "YES" : "NO") << "\n";
    }
}
