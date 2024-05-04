/**
 *    author:  MaGnsi0
 *    created: 11.04.2024 19:12:38
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 202;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, -1)));
    function<int(int, int, int)> solve = [&](int x, int y, int z) {
        if (x == 0 && y == 0 && z == 0) { return 1; }
        int& res = dp[x][y][z];
        if (res != -1) { return res; }
        int add = (x & 1) == (y & 1) && (y & 1) == (z & 1);
        if (x) { res = max(res, solve(x - 1, y, z) + add); }
        if (y) { res = max(res, solve(x, y - 1, z) + add); }
        if (z) { res = max(res, solve(x, y, z - 1) + add); }
        return res;
    };
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int k; cin >> k;
        int f; cin >> f;
        int ans = solve(n, m, k);
        if (ans) { ans += f / 2; }
        cout << ans - 1 << "\n";
    }
}
