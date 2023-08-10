/**
 *    author:  MaGnsi0
 *    created: 27.05.2023 15:39:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> deg(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
        deg[u - 1]++, deg[v - 1]++;
    }
    set<int> leafs;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            leafs.insert(i);
        }
    }
    vector<bool> done(n, false);
    vector<int> ans;
    while (!leafs.empty()) {
        int v = *leafs.begin();
        leafs.erase(v);
        int p = -1;
        for (int u : adj[v]) {
            if (!done[u]) {
                p = u;
                break;
            }
        }
        ans.push_back(adj[p].size());
        done[p] = true;
        for (int u : adj[p]) {
            leafs.erase(u);
            done[u] = true;
        }
        for (int u : adj[p]) {
            for (int k : adj[u]) {
                if (done[k]) { continue; }
                deg[k]--;
                if (deg[k] == 1) {
                    leafs.insert(k);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int x : ans) {
        cout << x << " ";
    }
}
