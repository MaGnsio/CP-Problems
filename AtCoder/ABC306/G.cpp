/**
 *    author:  MaGnsi0
 *    created: 18.06.2023 00:26:27
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
        vector<vector<vector<int>>> adj(2, vector<vector<int>>(n));
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[0][u - 1].push_back(v - 1);
            adj[1][v - 1].push_back(u - 1);
        }
        function<vector<int>(int)> bfs = [&](int j) {
            vector<int> ans(n, -1), b;
            ans[0] = 0, b.push_back(0);
            while (!b.empty()) {
                int v = b.back();
                b.pop_back();
                for (int u : adj[j][v]) {
                    if (ans[u] == -1) {
                        ans[u] = ans[v] + 1;
                        b.push_back(u);
                    }
                }
            }
            return ans;
        };
        vector<vector<int>> ans(2);
        ans[0] = bfs(0), ans[1] = bfs(1);
        int g = 0;
        for (int v = 0; v < n; ++v) {
            for (int u : adj[0][v]) {
                if (ans[0][v] != -1 && ans[1][u] != -1) {
                    g = __gcd(g, ans[0][v] + 1 - ans[0][u]);
                }
            }
        }
        cout << (g && 10000000 % g == 0 ? "Yes\n" : "No\n");
    }
}
