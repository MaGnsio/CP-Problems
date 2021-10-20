//https://www.e-olymp.com/en/contests/15667/problems/161002
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
    int N, CC = 0;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            if (x) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    vector<bool> V(N, false);
    for (int i = 0; i < N; ++i) {
        if (!V[i]) {
            dfs(G, V, i);
            CC++;
        }
    }
    cout << CC;
}
