//https://cses.fi/problemset/task/1666
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& G, vector<bool>& V, int v) {
    V[v] = true;
    for (auto& u : G[v]) {
        if (!V[u]) {
            dfs(G, V, u);
        }
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> R;
    vector<bool> V(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (!V[i]) {
            dfs(G, V, i);
            R.push_back(i);
        }
    }
    int K = R.size() - 1;
    cout << K << "\n";
    for (int i = 0; i < K; ++i) {
        cout << R[i] << " " << R[i + 1] << "\n";
    }
}
