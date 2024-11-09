/**
 *    author:  MaGnsi0
 *    created: 10.11.2024 00:37:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<set<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].emplace(v);
            adj[v].emplace(u);
        }
        set<pair<int, int>> deg;
        for (int i = 0; i < n; ++i) {
            deg.emplace((int)adj[i].size(), i);
        }
        vector<tuple<int, int, int>> ops;
        function<void(int, int, int)> do_op = [&](int v1, int v2, int v3) {
            deg.erase({(int)adj[v1].size(), v1});
            deg.erase({(int)adj[v2].size(), v2});
            deg.erase({(int)adj[v3].size(), v3});
            if (adj[v1].count(v2)) {
                adj[v1].erase(v2);
                adj[v2].erase(v1);
            } else {
                adj[v1].emplace(v2);
                adj[v2].emplace(v1);
            }
            if (adj[v2].count(v3)) {
                adj[v2].erase(v3);
                adj[v3].erase(v2);
            } else {
                adj[v2].emplace(v3);
                adj[v3].emplace(v2);
            }
            if (adj[v1].count(v3)) {
                adj[v1].erase(v3);
                adj[v3].erase(v1);
            } else {
                adj[v1].emplace(v3);
                adj[v3].emplace(v1);
            }
            deg.emplace((int)adj[v1].size(), v1);
            deg.emplace((int)adj[v2].size(), v2);
            deg.emplace((int)adj[v3].size(), v3);
            ops.emplace_back(v1 + 1, v2 + 1, v3 + 1);
        };
        while (true) {
            auto [d, v] = *deg.rbegin();
            if (d < 2) { break; }
            do_op(v, *adj[v].begin(), *adj[v].rbegin());
        }
        if (deg.rbegin() -> first) {
            int v1 = deg.rbegin() -> second;
            int v2 = *adj[v1].begin();
            set<int> to_connect;
            for (int i = 0; i < n; ++i) {
                if (i == v1) { continue; }
                if (i == v2) { continue; }
                int u1 = i;
                int u2 = adj[u1].empty() ? -1 : *adj[u1].begin();
                to_connect.emplace(max(u1, u2));
            }
            for (int v3 : to_connect) {
                do_op(v1, v2, v3);
                v2 = v3;
            }
        }
        cout << (int)ops.size() << "\n";
        for (auto [v1, v2, v3] : ops) {
            cout << v1 << " " << v2 << " " << v3 << "\n";
        }
    }
}
