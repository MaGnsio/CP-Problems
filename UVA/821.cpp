/**
 *    author:  MaGnsi0
 *    created: 22/06/2021 04:24:43
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n = 105, t = 0;
    while (true) {
        vector<bool> visited(n, false);
        vector<vector<int>> d(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            d[i][i] = 0;
        }
        for (int i = 0; ; ++i) {
            int u, v;
            cin >> u >> v;
            if (!u && !v && !i) {
                return 0;
            }
            if (!u && !v) {
                break;
            }
            d[u][v] = 1;
            visited[u] = visited[v] = true;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!(visited[k] && visited[i] && visited[j])) {
                        continue;
                    }
                    if (d[i][k] < INT_MAX && d[k][j] < INT_MAX) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }
        int sum = 0, x = count(visited.begin(), visited.end(), true);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!(visited[i] && visited[j])) {
                    continue;
                }
                sum += d[i][j];
            }
        }
        double res = sum / double(x * (x - 1));
        cout << "Case " << ++t << ": average length between pages = ";
        cout << fixed << setprecision(3) << res << " clicks\n";
    }
}
