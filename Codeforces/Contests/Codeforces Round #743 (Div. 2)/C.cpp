/**
 *    author:  MaGnsi0
 *    created: 18/09/2021 16:32:03
**/
#include <bits/stdc++.h>
using namespace std;

vector<int> topological_sort_kahn(int& n, vector<vector<int>>& adj, vector<int>& in_deg) {
    vector<int> topological_order;
    set<int> q;
    for (int i = 0; i < n; ++i) {
        if (!in_deg[i]) {
            q.insert(i);
        }
    }
    while (!q.empty()) {
        auto it = (topological_order.empty() ? q.begin() : q.lower_bound(topological_order.back()));
        if (it == q.end()) {
            it = q.begin();
        }
        int v = *it;
        q.erase(it);
        topological_order.push_back(v);
        for (auto& u : adj[v]) {
            in_deg[u]--;
            if (!in_deg[u]) {
                q.insert(u);
            }
        }
    }
    return topological_order;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> in_deg(n, 0);
        vector<vector<int>> adj(n);
        for (int v = 0; v < n; ++v) {
            int m;
            cin >> m;
            in_deg[v] = m;
            for (int i = 0; i < m; ++i) {
                int u;
                cin >> u;
                adj[u - 1].push_back(v);
            }
        }
        vector<int> v = topological_sort_kahn(n, adj, in_deg);
        if (v.size() != n) {
            cout << -1 << "\n";
            continue;
        }
        int res = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (v[i] > v[i + 1]) {
                res++;
            }
        }
        cout << res << "\n";
    }
}
