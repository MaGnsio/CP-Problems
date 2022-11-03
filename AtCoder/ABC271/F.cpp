/**
 *    author:  MaGnsi0
 *    created: 01.10.2022 20:08:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<map<int, int64_t>>> dp1(n, vector<map<int, int64_t>>(n));
    dp1[0][0][a[0][0]] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + j > n - 1) { continue; }
            if (i) {
                for (auto& [x, y] : dp1[i - 1][j]) {
                    dp1[i][j][x ^ a[i][j]] += y;
                }
            }
            if (j) {
                for (auto& [x, y] : dp1[i][j - 1]) {
                    dp1[i][j][x ^ a[i][j]] += y;
                }
            }
        }
    }
    vector<vector<map<int, int64_t>>> dp2(n, vector<map<int, int64_t>>(n));
    dp2[n - 1][n - 1][a[n - 1][n - 1]] = 1; 
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i + j < n - 1) { continue; }
            if (i + 1 < n) {
                for (auto& [x, y] : dp2[i + 1][j]) {
                    dp2[i][j][x ^ a[i][j]] += y;
                }
            }
            if (j + 1 < n) {
                for (auto& [x, y] : dp2[i][j + 1]) {
                    dp2[i][j][x ^ a[i][j]] += y;
                }
            }
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        for (auto& [x, y] : dp1[i][n - i - 1]) {
            if (dp2[i][n - i - 1].count(x ^ a[i][n - i - 1])) {
                ans += y * dp2[i][n - i - 1][x ^ a[i][n - i - 1]];
            }
        }
    }
    cout << ans;
}
