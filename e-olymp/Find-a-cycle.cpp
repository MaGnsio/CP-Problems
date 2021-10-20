//https://www.e-olymp.com/en/contests/8063/problems/67700
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<int>& color, vector<int>& parent, int& cycle_begin, int& cycle_end, int v, int par = -1) {
    color[v] = 1;
    parent[v] = par;
    for (auto& u : adj[v]) {
        if (color[u] == 2) {
            continue;
        }
        if (color[u] == 1) {
            cycle_begin = u;
            cycle_end = v;
            return true;
        }
        if (dfs(adj, color, parent, cycle_begin, cycle_end, u, v)) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<int> color(N + 1, 0), parent(N + 1, -1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= N; ++i) {
        int cycle_begin = -1, cycle_end = -1;
        if (color[i] == 0 && dfs(adj, color, parent, cycle_begin, cycle_end, i)) {
            vector<int> cycle;
            for (int v = cycle_end; v != cycle_begin; v = parent[v]) {
                cycle.push_back(v);
            }
            cycle.push_back(cycle_begin);
            reverse(cycle.begin(), cycle.end());
            cout << "YES\n";
            for (auto& v : cycle) {
                cout << v << " ";
            }
            return 0;
        }
    }
    cout << "NO";
}
