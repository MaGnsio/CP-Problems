/**
 *    author:  MaGnsi0
 *    created: 10/07/2021 03:19:28
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

void dfs1(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& top_sort, int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs1(adj, visited, top_sort, u);
        }
    }
    top_sort.push_back(v);
}

void dfs2(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& a, vector<int>& scc, int v) {
    visited[v] = true;
    scc.push_back(a[v]);
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs2(adj, visited, a, scc, u);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, s = 0, w = 1;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> adj(n), adjT(n);
    for (auto& x : a) {
        cin >> x;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
    vector<int> top_sort;
    vector<bool> visited(n, false);
    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            dfs1(adj, visited, top_sort, v);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    visited.assign(n, false);
    for (auto& v : top_sort) {
        if (!visited[v]) {
            int cnt = 0;
            vector<int> scc;
            dfs2(adjT, visited, a, scc, v);
            sort(scc.begin(), scc.end());
            for (auto& x : scc) {
                if (x == scc[0]) {
                    cnt++;
                } else {
                    break;
                }
            }
            w = ((w % mod) * (cnt % mod)) % mod;
            s += scc[0];
        }
    }
    cout << s << " " << w;
}
