/**
 *    author:  MaGnsi0
 *    created: 04/08/2021 07:26:11
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> x(n + 2), y(n + 2), p(n + 2);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i] >> p[i];
        }
        cin >> x[n] >> y[n] >> x[n + 1] >> y[n + 1];
        vector<vector<int>> d(n + 2, vector<int>(n + 2));
        for (int i = 0; i < n + 2; ++i) {
            for (int j = 0; j < n + 2; ++j) {
                d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= p[i] * p[i]) {
                    d[i][j] = min(2LL, d[i][j]);
                }
            }
        }
        for (int k = 0; k < n + 2; ++k) {
            for (int i = 0; i < n + 2; ++i) {
                for (int j = 0; j < n + 2; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        cout << d[n][n + 1] << "\n";
    }
}
