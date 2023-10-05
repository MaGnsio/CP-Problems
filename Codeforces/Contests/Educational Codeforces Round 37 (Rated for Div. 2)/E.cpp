/**
 *    author:  MaGnsi0
 *    created: 29.04.2022 16:07:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].insert(v - 1);
        adj[v - 1].insert(u - 1);
    }
    set<int> visited;
    for (int i = 0; i < n; ++i) {
        visited.insert(i);
    }
    function<int(int)> DFS = [&](int v) {
        visited.erase(v);
        int cnt = 1;
        for (int u = -1;;) {
            if (visited.upper_bound(u) == visited.end()) {
                break;
            }
            u = *visited.upper_bound(u);
            if (adj[v].count(u) == 0) {
                cnt += DFS(u);
            }
        }
        for (auto& u : visited) {
            if (adj[v].count(u) == 0) {
                cnt += DFS(u);
            }
        }
        return cnt;
    };
    vector<int> ans;
    while (!visited.empty()) {
        ans.push_back(DFS(*visited.begin()));
    }
    sort(ans.begin(), ans.end());
    cout << (int)ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}
