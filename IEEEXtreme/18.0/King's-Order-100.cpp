/**
 *    author:  MaGnsi0
 *    created: 26.10.2024 18:06:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<int> in_deg(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u;
        int v; cin >> v;
        adj[u - 1].push_back(v - 1);
        in_deg[v - 1]++;
    }
    vector<int> topological_order;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 0; i < n; ++i) {
        if (!in_deg[i]) { q.emplace(p[i], i); }
    }
    while (!q.empty()) {
        int v = q.top().second; q.pop();
        topological_order.push_back(v);
        for (auto& u : adj[v]) {
            in_deg[u]--;
            if (!in_deg[u]) { q.emplace(p[u], u); }
        }
    }
    if ((int)topological_order.size() != n) {
        cout << -1;
        return 0;
    }
    for (int v : topological_order) {
        cout << v + 1 << " ";
    }
}
