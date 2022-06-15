/**
 *    author:  MaGnsi0
 *    created: 10.04.2022 01:05:38
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
    vector<int> depth(n, 0), subtree_size(n, 1), res(n);
    vector<map<int, int>> a(n); //[depth, no. of nodes with such depth]
    vector<set<pair<int, int>>> b(n); //[no. of nodes with such depth, depth]
    function<void(int, int)> DFS = [&](int v, int p) {
        depth[v] = (v ? depth[p] + 1 : 0);
        int large = -1;
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            DFS(u, v);
            subtree_size[v] += subtree_size[u];
            if (large == -1 || subtree_size[u] > subtree_size[large]) {
                large = u;
            }
        }
        if (large != -1) {
            a[v].swap(a[large]);
            b[v].swap(b[large]);
        }
        for (auto& u : adj[v]) {
            if (u == p || u == large) {
                continue;
            }
            for (auto& [x, y] : a[u]) {
                if (a[v].count(-x)) {
                    b[v].erase(make_pair(a[v][x], -x));
                }
                a[v][x] += y;
                b[v].insert(make_pair(a[v][x], -x));
            }
        }
        a[v][depth[v]] = 1;
        b[v].insert(make_pair(1, -depth[v]));
        res[v] = -(b[v].rbegin() -> second) - depth[v];
    };
    DFS(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << res[i] << "\n";
    }
}
