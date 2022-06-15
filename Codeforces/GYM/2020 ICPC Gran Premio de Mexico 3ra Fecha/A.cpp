/**
 *    author:  MaGnsi0
 *    created: 12.05.2022 21:07:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, P;
    cin >> T >> P;
    vector<int> a(T), b(P), c(P);
    for (int i = 0; i < T; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < P; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < P; ++i) {
        cin >> c[i];
    }
    int N = (1 << T);
    vector<vector<vector<int>>> dp(P, vector<vector<int>>(101, vector<int>(N, -1)));
    function<int(int, int, int)> solve = [&](int x, int y, int z) {
        if (x == P) {
            return 0;
        }
        int& ans = dp[x][y][z];
        if (ans != -1) {
            return ans;
        }
        ans = solve(x + 1, y, z);
        for (int i = 0; i < T; ++i) {
            if (!((z >> i) & 1)) {
                ans = max(ans, solve(x, a[i], z | (1 << i)));
            }
        }
        if (b[x] <= y) {
            ans = max(ans, c[x] + solve(x + 1, y - b[x], z));
        }
        return ans;
    };
    int ans = 0;
    for (int i = 0; i < T; ++i) {
        ans = max(ans, solve(0, a[i], (1 << i)));
    }
    cout << ans;
}
