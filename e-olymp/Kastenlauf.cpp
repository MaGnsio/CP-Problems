//https://www.e-olymp.com/en/problems/6033?fbclid=IwAR2ttynFRW4c0o-9RLcGnlW40wAY3_0D08HSiGxj2RLoR_mAQzaE9M4RICo
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& G, vector<bool>& V, int v, int t) {
    V[v] = true;
    for (auto& u : G[v]) {
        if (u == t) {
            return true;
        }
        if (!V[u] && dfs(G, V, u, t)) {
            return true;
        }
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> A(N + 3);
        for (int i = 1; i <= N + 2; ++i) {
            cin >> A[i].first >> A[i].second;
        }
        vector<vector<int>> G(N + 3);
        for (int i = 1; i <= N + 2; ++i) {
            for (int j = i + 1; j <= N + 2; ++j) {
                int dis = abs(A[i].first - A[j].first) + abs(A[i].second - A[j].second);
                if (dis <= 1000) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        vector<bool> V(N + 3, false);
        cout << (dfs(G, V, 1, N + 2) ? "happy" : "sad") << "\n";
    }
}
