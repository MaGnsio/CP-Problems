//https://codeforces.com/problemset/problem/580/C
#include <bits/stdc++.h>
using namespace std;

void dfs(int M, int& R, vector<vector<int>>& G, vector<bool>& V, vector<bool>& C, int i = 0, int c = 0){
    V[i] = true;
    if (c + C[i] > M) {
        return;
    }
    int nc = (C[i] ? c + 1 : 0);
    bool isLeaf = true;
    for (auto& x : G[i]) {
        if (!V[x]) {
            isLeaf = false;
            dfs(M, R, G, V, C, x, nc);
        }
    }
    R += isLeaf;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M, R = 0;
    cin >> N >> M;
    vector<bool> C(N), V(N, false);
    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        C[i] = c;
    }
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
    }
    dfs(M, R, G, V, C);
    cout << R;
}
