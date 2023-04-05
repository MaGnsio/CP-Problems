/**
 *    author:  MaGnsi0
 *    created: 22.01.2023 22:42:02
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
        if (m == 0) {
            cout << "YES" << "\n";
            continue;
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        //Finding cycles
        vector<int> deg(n);
        for (int i = 0; i < n; ++i) {
            deg[i] = (int)adj[i].size();
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) { q.push(i); deg[i] = 0; }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& u : adj[v]) {
                if (deg[u] == 0) { continue; }
                deg[u]--;
                if (deg[u] == 1) { q.push(u); deg[u] = 0; }
            }
        }
        int tree_nodes = 0, cycle_nodes = 0;
        for (int i = 0; i < n; ++i) {
            tree_nodes += deg[i] == 0;
            cycle_nodes += deg[i] == 2;
        }
        if (tree_nodes + cycle_nodes != n) {
            cout << "NO\n";
            continue;
        }
        if (tree_nodes == n) {
            cout << "YES\n";
            continue;
        }
        vector<bool> visited(n, false);
        vector<int> color(n, 0);
        function<void(int, int)> go = [&](int v, int c) {
            color[v] = c;
            visited[v] = true;
            for (auto& u : adj[v]) {
                if (deg[u] != 2 || visited[u]) { continue; }
                go(u, c ^ 1);
            }
        };
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 2) { go(i, 0); break; }
        }
        if (count(visited.begin(), visited.end(), true) != cycle_nodes) {
            cout << "NO\n";
            continue;
        }
        //Finding the canonical form of the suptrees of cycle_nodes
        vector<int> sup(n);
        vector<string> val(n, "");
        function<void(int, int)> dfs = [&](int v, int p) {
            sup[v] = 1;
            for (auto& u : adj[v]) {
                if (u == p || deg[u] == 2) { continue; }
                dfs(u, v);
                sup[v] += sup[u];
            }
            sort(adj[v].begin(), adj[v].end(), [&](int x, int y) {
                    return val[x] < val[y];
                });
            val[v] = "1";
            for (auto& u : adj[v]) {
                if (u == p || deg[u] == 2) { continue; }
                val[v] += val[u];;
            }
            val[v] += "0";
        };
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 2) { dfs(i, -1); }
        }
        assert(cycle_nodes > 2);
        if (cycle_nodes & 1) {
            set<string> s;
            for (int i = 0; i < n; ++i) {
                if (deg[i] == 2) { s.insert(val[i]); }
            }
            cout << ((int)s.size() == 1 ? "YES" : "NO") << "\n";
        } else {
            vector<set<string>> s(2);
            for (int i = 0; i < n; ++i) {
                if (deg[i] == 2) { s[color[i]].insert(val[i]); }
            }
            cout << ((int)s[0].size() == 1 && (int)s[1].size() == 1 ? "YES" : "NO") << "\n";
        }
    }
}
