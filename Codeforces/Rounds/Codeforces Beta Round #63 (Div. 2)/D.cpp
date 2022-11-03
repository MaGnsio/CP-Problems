/**
 *    author:  MaGnsi0
 *    created: 24.09.2022 15:31:35
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 505, offset = 200;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y, n, d;
    cin >> x >> y >> n >> d;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<vector<int>> dp(N, vector<int>(N, -1));
    function<int(int, int)> solve = [&](int x, int y) {
        if (x * x + y * y > d * d) {
            return 1;
        }
        if (dp[x + offset][y + offset] != -1) {
            return dp[x + offset][y + offset];
        }
        dp[x + offset][y + offset] = 0;
        for (int i = 0; i < n; ++i) {
            dp[x + offset][y + offset] |= !solve(x + a[i], y + b[i]);
        }
        return dp[x + offset][y + offset];
    };
    cout << (solve(x, y) ? "Anton" : "Dasha");
}
