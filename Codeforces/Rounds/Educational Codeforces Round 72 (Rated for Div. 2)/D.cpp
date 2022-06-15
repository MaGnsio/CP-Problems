/**
 *    author:  MaGnsi0
 *    created: 25.04.2022 12:02:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(make_pair(v - 1, i));
    }
    int k = 1;
    vector<int> color(n, 0), ans(m, 1);
    function<void(int)> dfs = [&](int v) {
        color[v] = 1;
        for (auto& [u, i] : adj[v]) {
            if (color[u] == 0) {
                dfs(u);
            } else if (color[u] == 1) {
                ans[i] = 2;
                k = 2;
            }
        }
        color[v] = 2;
    };
    for (int i = 0; i < n; ++i) {
        if (!color[i]) {
            dfs(i);
        }
    }
    cout << k << "\n";
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << " ";
    }
}
