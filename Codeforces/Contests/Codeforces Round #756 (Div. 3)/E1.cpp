/**
 *    author:  MaGnsi0
 *    created: 25.11.2021 16:25:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i], a[i]--;
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> d(n, 0);
        function<void(int, int, int)> dfs = [&](int v, int p, int dis) {
            d[v] = dis;
            for (auto& u : adj[v]) {
                if (u != p) {
                    dfs(u, v, dis + 1);
                }
            }
        };
        dfs(0, -1, 0);
        queue<int> q;
        vector<int> df(n, 1e6);
        for (int i = 0; i < k; ++i) {
            q.push(a[i]);
            df[a[i]] = 0;
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& u : adj[v]) {
                if (df[v] + 1 < df[u]) {
                    q.push(u);
                    df[u] = df[v] + 1;
                }
            }
        }
        bool ok = false;
        for (int i = 1; i < n; ++i) {
            ok |= (d[i] < df[i] && adj[i].size() == 1);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
