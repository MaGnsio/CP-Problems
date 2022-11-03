/**
 *    author:  MaGnsi0
 *    created: 18.06.2022 14:11:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> H(3), W(3);
    for (int i = 0; i < 3; ++i) {
        cin >> H[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin >> W[i];
    }
    int ans = 0;
    vector<vector<int>> a(3, vector<int>(3));
    function<bool()> good = [&]() {
        for (int i = 0; i < 3; ++i) {
            if (a[i][0] + a[i][1] + a[i][2] != H[i]) {
                return false;
            }
            if (a[0][i] + a[1][i] + a[2][i] != W[i]) {
                return false;
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (a[i][j] < 1) {
                    return false;
                }
            }
        }
        return true;
    };
    function<void(int, int)> solve = [&](int x, int y) {
        if (x == 2) {
            assert(y == 0);
            a[0][2] = H[0] - a[0][0] - a[0][1];
            a[1][2] = H[1] - a[1][0] - a[1][1];
            a[2][0] = W[0] - a[0][0] - a[1][0];
            a[2][1] = W[1] - a[0][1] - a[1][1];
            a[2][2] = W[2] - a[0][2] - a[1][2];
            ans += good();
            return;
        }
        for (int i = 1; i <= 30; ++i) {
            a[x][y] = i;
            (y == 1 ? solve(x + 1, 0) : solve(x, y + 1));
        }
    };
    solve(0, 0);
    cout << ans;
}
