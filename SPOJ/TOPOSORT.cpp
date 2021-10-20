/**
 *    author:  MaGnsi0
 *    created: 02/07/2021 05:57:15
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<int> in_deg(n + 1, 0), topo_sort;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_deg[v]++;
    }
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        if (!in_deg[i]) {
            s.insert(i);
        }
    }
    while (!s.empty()) {
        int v = *s.begin();
        s.erase(s.begin());
        topo_sort.push_back(v);
        cnt++;
        for (auto& u : adj[v]) {
            in_deg[u]--;
            if (!in_deg[u]) {
                s.insert(u);
            }
        }
    }
    if (cnt != n) {
        cout << "Sandro fails.";
        return 0;
    }
    for (auto& v : topo_sort) {
        cout << v << " ";
    }
}
