/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 22:01:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int F0 = 1, F1 = 1;
    set<int> F;
    while (F1 <= n) {
        F.insert(F1);
        int T = F1;
        F1 = F0 + F1;
        F0 = T;
    }
    if (F.count(n) == 0) {
        cout << "NO";
        return 0;
    }
    if (n == 1) {
        cout << "YES";
        return 0;
    }
    bool ok = false;
    vector<int> size(n), is_root(n, 0), parent(n, -1);
    vector<pair<int, int>> sizes;
    function<void(int, int)> dfs = [&](int v, int p) {
        size[v] = 1;
        parent[v] = p;
        for (int u : adj[v]) {
            if (u == p || is_root[u]) { continue; }
            dfs(u, v);
            size[v] += size[u];
        }
        sizes.emplace_back(size[v], v);
    };
    function<bool(int, int)> solve = [&](int v, int p) {
        sizes.clear();
        dfs(v, p);
        if (size[v] == 1) { return true; } 
        sort(sizes.rbegin(), sizes.rend());
        bool good = false;
        for (auto [s, u] : sizes) {
            if (u == v) { continue; }
            if (F.count(s) && F.count(size[v] - s)) {
                is_root[u] = 1;
                good |= solve(u, parent[u]) && solve(v, parent[v]);
                is_root[u] = 0;
            }
        }
        return good;
    };
    cout << (solve(0, -1) ? "YES" : "NO");
}
