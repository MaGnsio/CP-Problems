/**
 *    author:  MaGnsi0
 *    created: 08.01.2023 16:42:38
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
        int k = n * n - 1;
        vector<vector<int>> a(n, vector<int>(n));
        int cur = 0, x = 1, y = n * n;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                for (int j = 0; j < n; ++j) {
                    a[i][j] = (cur ? x++ : y--);
                    cur ^= 1;
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    a[i][j] = (cur ? x++ : y--);
                    cur ^= 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
