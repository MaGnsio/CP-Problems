//https://www.e-olymp.com/en/contests/15667/problems/160999
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& G, vector<bool>& V, int v) {
    V[v] = true;
    cout << v << " ";
    for (auto& x : G[v]) {
        if (!V[x]) {
            dfs(G, V, x);
        }
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M, v;
    cin >> N >> M;
    vector<vector<int>> G(N + 1);
    vector<bool> V(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> v;
    dfs(G, V, v);
}
