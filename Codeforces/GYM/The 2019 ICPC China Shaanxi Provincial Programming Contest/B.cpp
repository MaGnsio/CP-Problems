/**
 *    author:  MaGnsi0
 *    created: 15.09.2023 17:45:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
            }
        }
        function<int(int, int)> I = [&](int i, int j) {
            return i * m + j;
        };
        function<bool(int, int)> valid = [&](int i, int j) {
            if (i < 0 || i >= n) { return false; }
            if (j < 0 || j >= m) { return false; }
            return true;
        };
        vector<int> deg(n * m, 0);
        vector<vector<int>> adj(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int ni = i, nj = j;
                if (a[i][j] == 'u') {
                    ni = i - b[i][j];
                } else if (a[i][j] == 'd') {
                    ni = i + b[i][j];
                } else if (a[i][j] == 'l') {
                    nj = j - b[i][j];
                } else {
                    nj = j + b[i][j];
                }
                if (valid(ni, nj)) {
                    adj[I(i, j)].push_back(I(ni, nj));
                    deg[I(ni, nj)]++;
                }
            }
        }
        int start = 0;
        vector<bool> visited(n * m, false);
        function<void(int)> dfs = [&](int v) {
            visited[v] = true;
            for (int u : adj[v]) {
                if (!visited[u]) {
                    dfs(u);
                }
            }
        };
        for (int i = 0; i < n * m; ++i) {
            if (deg[i] == 0) { start = i; }
        }
        dfs(start);
        bool ok = count(visited.begin(), visited.end(), true) == n * m;
        cout << (ok ? "Yes" : "No") << "\n";
    }
}
