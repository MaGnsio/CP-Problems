//https://www.e-olymp.com/en/contests/15667/problems/161001
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& G, vector<bool>& V, int& u, int& v, int i, int par = -1) {
    V[i] = true;
    for (auto& j : G[i]) {
        if (j == par) {
            continue;
        }
        if (V[j] == true) {
            u = i, v = j;
            return true;
        }
        if (dfs(G, V, u, v, j, i)) {
            return true;
        }
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1);
    while(M--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    while (true) {
        int u, v;
        bool isTree = true;
        vector<bool> V(N + 1, false);
        for (int i = 1; i <= N; ++i) {
            if (V[i] == false && dfs(G, V, u, v, i)) {
                G[u].erase(find(G[u].begin(), G[u].end(), v));
                G[v].erase(find(G[v].begin(), G[v].end(), u));
                isTree = false;
                break;
            }
        }
        if (isTree) {
            break;
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < G[i].size(); ++j) {
            if (G[i][j] > i) {
                cout << i << " " << G[i][j] << "\n";
            }
        }
    }
}
