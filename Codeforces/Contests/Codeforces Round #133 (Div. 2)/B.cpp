//https://codeforces.com/contest/216/problem/B
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& G, vector<bool>& V, int v, int par = -1) {
    V[v] = true;
    for (auto& u : G[v]) {
        if (u == par) {
            continue;
        }
        if (V[u]) {
            return true;
        }
        if (dfs(G, V, u, v)) {
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
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int B = 0, K = 0;
    vector<bool> V(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (!V[i] && dfs(G, V, i)) {
            int k = count(V.begin(), V.end(), true);
            B += ((k - K) & 1);
        }
        K = count(V.begin(), V.end(), true);
    }
    cout << B + ((N - B) & 1);
}
