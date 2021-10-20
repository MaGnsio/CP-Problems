/**
 *    author:  MaGnsi0
 *    created: 31/07/2021 10:03:28
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int& cnt, int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs(adj, visited, cnt, u);
        }
    }
    cnt++;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, k;
    cin >> n >> m >> k;
    set<string> s;
    vector<pair<string, string>> e(m);
    for (auto& [u, v] : e) {
        cin >> u >> v;
        s.insert(u);
        s.insert(v);
    }
    int cur = 0;
    map<string, int> p;
    for (auto& x : s) {
        p[x] = cur++;
    }
    vector<vector<int>> adj(n);
    for (auto& [u, v] : e) {
        adj[p[u]].push_back(p[v]);
        adj[p[v]].push_back(p[u]);
    }
    vector<int> cc;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int cnt = 0;
            dfs(adj, visited, cnt, i);
            cc.push_back(cnt);
        }
    }
    sort(cc.begin(), cc.end(), greater<int>());
    int res = 0;
    for (int i = 0; i < min(k, (int)cc.size()); ++i) {
        res += cc[i];
    }
    cout << res;
}
