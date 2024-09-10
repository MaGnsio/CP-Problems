/**
 *    author:  MaGnsi0
 *    created: 10.09.2024 22:57:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i]; c[i]--;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int64_t> ans(n), subtree(n);
    vector<map<int, int64_t>> countF(n), countC(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        int big = -1;
        subtree[v] = 1;
        for (int u : adj[v]) {
            if (u == p) { continue; }
            dfs(u, v);
            subtree[v] += subtree[u];
            if (big == -1 || countC[u].size() > countC[big].size()) {
                big = u;
            }
        }
        if (big != -1) {
            countF[v].swap(countF[big]);
            countC[v].swap(countC[big]);
        }
        for (int u : adj[v]) {
            if (u == p) { continue; }
            if (u == big) { continue; }
            for (auto [x, y] : countC[u]) {
                if (countC[v].count(x)) {
                    countF[v][countC[v][x]] -= x + 1;
                }
                countC[v][x] += y;
                countF[v][countC[v][x]] += x + 1;
            }
        }
        if (countC[v].count(c[v])) {
            countF[v][countC[v][c[v]]] -= c[v] + 1;
        }
        countC[v][c[v]]++;
        countF[v][countC[v][c[v]]] += c[v] + 1;
        ans[v] = countF[v].rbegin() -> second;
    };
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
