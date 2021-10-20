//https://www.e-olymp.com/en/contests/15667/problems/161000
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& G, vector<bool>& V, vector<int>& D, vector<int>& F, int& T, int v) {
    V[v] = true;
    D[v] = T++;
    for (auto& x : G[v]) {
        if (!V[x]) {
            dfs(G, V, D, F, T, x);
        }
    }
    F[v] = T++;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M, v, T = 1;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
    }
    cin >> v;
    vector<int> D(N, 0), F(N, 0);
    vector<bool> V(N, false);
    dfs(G, V, D, F, T, v - 1);
    for (int i = 0; i < N; ++i) {
        cout << D[i] << " " << F[i] << "\n";
    }
}
