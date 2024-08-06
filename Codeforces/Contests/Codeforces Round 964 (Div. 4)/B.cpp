/**
 *    author:  MaGnsi0
 *    created: 06.08.2024 17:52:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int a[2][2];
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < 2; ++i) {
           ans += ((a[0][0] > a[1][i] ? 1 : (a[0][0] < a[1][i] ? -1 : 0)) + (a[0][1] > a[1][i ^ 1] ? 1 : (a[0][1] < a[1][i ^ 1] ? -1 : 0))) > 0;
        }
        cout << 2 * ans << "\n";
    }
}
