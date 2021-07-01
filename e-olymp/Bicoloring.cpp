//https://www.e-olymp.com/en/contests/8063/problems/67702
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<set<int>>& adj, vector<int>& color, int v, int c = 1) {
    color[v] = c;
    for (auto& u : adj[v]) {
        if (color[v] == color[u]) {
            return false;
        }
        if (color[u] == 0) {
            if (!dfs(adj, color, u, (c == 1 ? 2 : 1))) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    while ((cin >> N) && N) {
        int M;
        cin >> M;
        vector<set<int>> adj(N + 1);
        vector<int> color(N + 1, 0);
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        cout << (dfs(adj, color, 1) ? "BICOLOURABLE.\n" : "NOT BICOLOURABLE.\n");
    }
}
