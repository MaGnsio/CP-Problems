//https://cses.fi/problemset/task/1678/
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& G, vector<int>& C, vector<int>& P, int& cycleStart, int& cycleEnd, int v) {
    C[v] = 1;
    for (auto& u : G[v]) {
        if (C[u] == 1) {
            cycleStart = u;
            cycleEnd = v;
            return true;
        }
        if (C[u] == 0) {
            P[u] = v;
            if (dfs(G, C, P, cycleStart, cycleEnd, u)) {
                return true;
            }
        }
    }
    C[v] = 2;
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
    }
    int cycleStart = -1, cycleEnd = -1;
    vector<int> C(N + 1, 0), P(N + 1, -1);
    for (int i = 1; i <= N; ++i) {
        if (C[i] == 0 && dfs(G, C, P, cycleStart, cycleEnd, i)) {
            break;
        }
    }
    if (cycleStart == -1) {
        cout << "IMPOSSIBLE";
    } else {
        vector<int> Cy;
        Cy.push_back(cycleStart);
        for (int x = cycleEnd; x != cycleStart; x = P[x]) {
            Cy.push_back(x);
        }
        Cy.push_back(cycleStart);
        reverse(Cy.begin(), Cy.end());
        cout << Cy.size() << "\n";
        for (auto& x : Cy) {
            cout << x << " ";
        }
    }
}
