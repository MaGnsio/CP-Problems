/**
 *    author:  MaGnsi0
 *    created: 29/09/2021 23:21:31
**/
#include <bits/stdc++.h>
using namespace std;

int dp[31][31][51];

int f(int x, int y, int z) {
    if (dp[x][y][z] != 0 || x * y == z || z == 0) {
        return dp[x][y][z];
    }
    dp[x][y][z] = 1e9;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j <= z; ++j) {
            dp[x][y][z] = min(dp[x][y][z], y * y + f(x - i, y, z - j) + f(i, y, j));
        }
    }
    for (int i = 1; i <= y; ++i) {
        for (int j = 0; j <= z; ++j) {
            dp[x][y][z] = min(dp[x][y][z], x * x + f(x, y - i, z - j) + f(x, i, j));
        }
    }
    return dp[x][y][z];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << f(n, m, k) << "\n";
    }
}
