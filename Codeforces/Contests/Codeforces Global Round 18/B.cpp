/**
 *    author:  MaGnsi0
 *    created: 25.12.2021 17:43:58
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    vector<vector<int>> f(N, vector<int>(30, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 30; ++j) {
            f[i][j] = ((i >> j) & 1);
        }
    }
    for (int j = 0; j < 30; ++j) {
        for (int i = 1; i < N; ++i) {
            f[i][j] += f[i - 1][j];
        }
    }
    while (T--) {
        int l, r;
        cin >> l >> r;
        int res = INT_MAX;
        for (int i = 0; i < 30; ++i) {
            res = min(res, (r - l + 1) - (f[r][i] - f[l - 1][i]));
        }
        cout << res << "\n";
    }
}
