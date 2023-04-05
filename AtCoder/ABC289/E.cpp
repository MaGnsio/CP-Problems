/**
 *    author:  MaGnsi0
 *    created: 11.02.2023 14:44:52
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        queue<pair<int, int>> q;
        vector<vector<int>> d(n, vector<int>(n, -1));
        q.emplace(0, n - 1);
        d[0][n - 1] = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (auto& cx : adj[x]) {
                for (auto& cy : adj[y]) {
                    if (a[cx] != a[cy] && d[cx][cy] == -1) {
                        q.emplace(cx, cy);
                        d[cx][cy] = d[x][y] + 1;
                    }
                }
            }
        }
        cout << d[n - 1][0] << "\n";
    }
}
