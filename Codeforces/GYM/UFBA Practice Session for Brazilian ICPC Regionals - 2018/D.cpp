/**
 *    author:  MaGnsi0
 *    created: 06.09.2023 20:56:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> adj(2, vector<vector<int>>(n));
    for (int i = 0; i < m; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }
    set<pair<int, int>> candidates;
    vector<vector<bool>> visited(2, vector<bool>(n, false));
    function<void(int, int)> dfs = [&](int j, int v) {
        visited[j][v] = true;
        for (int u : adj[j][v]) {
            if (visited[j][u]) { continue; }
            if (j) {
                candidates.emplace(u, v);
            } else {
                candidates.emplace(v, u);
            }
            dfs(j, u);
        }
    };
    function<void(int, pair<int, int>)> F = [&](int v, pair<int, int> banned) {
        visited[0][v] = true;
        bool found_banned = false;
        for (int u : adj[0][v]) {
            if (visited[0][u]) { continue; }
            if (!found_banned && make_pair(v, u) == banned) {
                found_banned = true;
                continue;
            }
            F(u, banned);
        }
    };
    dfs(0, 0), dfs(1, 0);
    vector<pair<int, int>> ans;
    for (auto candidate : candidates) {
        visited[0] = vector<bool>(n, false);
        F(candidate.first, candidate);
        if (visited[0][candidate.second] == false) {
            ans.emplace_back(candidate);
        }
    }
    cout << (int)ans.size() << "\n";
    for (auto [u, v] : ans) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
}
