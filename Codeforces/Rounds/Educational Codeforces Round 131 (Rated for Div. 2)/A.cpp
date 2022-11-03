/**
 *    author:  MaGnsi0
 *    created: 08.07.2022 22:15:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        vector<vector<int>> a(2, vector<int>(2));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cin >> a[i][j];
            }
        }
        int sum = a[0][0] + a[0][1] + a[1][0] + a[1][1];
        if (sum == 0) {
            cout << 0 << "\n";
        } else if (sum < 4) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}
