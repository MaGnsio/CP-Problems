/**
 *    author:  MaGnsi0
 *    created: 19.12.2024 23:59:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> deg(n);
    vector<set<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++, deg[v]++;
    }
    vector<int> val(n, 1);
    set<pair<int, int>> leafs;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            leafs.emplace(val[i], i);
        }
    }
    int done = 0;
    while (!leafs.empty()) {
        int leaf = leafs.begin() -> second; leafs.erase(leafs.begin());
        int p = *adj[leaf].begin();
        if (val[p] < val[leaf]) {
            cout << "NO";
            return 0;
        }
        val[p] += val[leaf]; val[leaf] = 0;
        adj[p].erase(leaf); adj[leaf].erase(p);
        deg[p]--, deg[leaf]--;
        if (deg[p] == 1) {
            leafs.emplace(val[p], p);
        }
        if (++done == n - 1) { break; }
    }
    cout << "YES";
}
