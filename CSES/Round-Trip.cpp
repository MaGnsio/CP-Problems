//https://cses.fi/problemset/task/1669
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<int>& v, vector<int>& p, int& start, int& end, int x, int par = -1) {
    v[x] = 1;
    p[x] = par;
    for (auto& y : adj[x]) {
        if (y == par) {
            continue;
        }
        if (v[y]) {
            start = y;
            end = x;
            return true;
        }
        if (dfs(adj, v, p, start, end, y, x)) {
            return true;
        }
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start = -1, end = -1;
    vector<int> v(n + 1, 0), p(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (!v[i] && dfs(adj, v, p, start, end, i)) {
            break;
        }
    }
    if (start == -1) {
        cout << "IMPOSSIBLE";
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int i = end; i != start; i = p[i]) {
            cycle.push_back(i);
        }
        cycle.push_back(start);
        cout << cycle.size() << "\n";
        for (auto& x : cycle) {
            cout << x << " ";
        }
    }
}
