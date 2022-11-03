/**
 *    author:  MaGnsi0
 *    created: 22.10.2022 03:13:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, d;
        cin >> n >> m >> d;
        char a[d][n][m];
        for (int k = 0; k < d; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cin >> a[k][i][j];
                }
            }
        }
    }
}
