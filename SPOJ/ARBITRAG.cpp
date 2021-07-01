/**
 *    author:  MaGnsi0
 *    created: 21/06/2021 20:40:35
**/
#include <bits/stdc++.h>
using namespace std;
const double OO = 1e-9;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, T = 0;
    while ((cin >> n) && n) {
        map<string, int> strToInt;
        for (int i = 0; i < n; ++i) {
            string curr;
            cin >> curr;
            strToInt[curr] = i;
        }
        vector<vector<double>> d(n, vector<double>(n, OO));
        for (int i = 0; i < n; ++i) {
            d[i][i] = 1.0;
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int u, v;
            double w;
            string x, y;
            cin >> x >> w >> y;
            u = strToInt[x], v = strToInt[y];
            d[u][v] = w;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (d[i][k] > OO && d[k][j] > OO) {
                        d[i][j] = max(d[i][j], d[i][k] * d[k][j]);
                    }
                }
            }
        }
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (d[i][i] > 1.0) {
                ok = true;
                break;
            }
        }
        cout << "Case " << ++T << ": " << (ok ? "Yes\n" : "No\n");
    }
}
