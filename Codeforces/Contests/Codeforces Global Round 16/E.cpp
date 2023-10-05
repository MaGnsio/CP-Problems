/**
 *    author:  MaGnsi0
 *    created: 12/09/2021 16:29:25
**/
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& adj, vector<pair<int, int>>& depth, int v, int par = -1) {
    for (auto& u : adj[v]) {
        if (u != par) {
            depth[v].first = max(depth[v].first, 1 + dfs(adj, depth, u, v));
        }
    }
    return depth[v].first;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<pair<int, int>> depth(n, {0, 0});
        for (int i = 0; i < n; ++i) {
            depth[i].second = i;
        }
        dfs(adj, depth, 0);
        if (depth[0].first == 1) {
            cout << n - 1 << "\n";
            continue;
        }
        sort(depth.begin(), depth.end());
        vector<int> v;
        vector<bool> visited(n, false);
        visited[0] = true;
        for (int i = 0; i < n; ++i) {
            if (depth[i].second == 0) {
                continue;
            }
            if (depth[i].first) {
                int x = (int)adj[depth[i].second].size();
                for (auto& u : adj[depth[i].second]) {
                    if (visited[u] && u != 0) {
                        x--;
                    }
                }
                if (x > 1) {
                    visited[depth[i].second] = true;
                    v.push_back(x);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < v.size(); ++i) {
            sum += v[i];
        }
        int leafs = (sum - v.size()), rn = 0;
        for (auto& u : adj[0]) {
            if (visited[u]) {
                continue;
            }
            rn++;
        }
        cout << leafs + rn - v.size() + (rn ? 0 : 1) << "\n";
    }
}
