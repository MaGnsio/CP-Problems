/**
 *    author:  MaGnsi0
 *    created: 16.06.2022 16:35:00
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> roads(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        roads[u - 1]++;
        adj[v - 1].push_back(u - 1);
    }
    vector<int> ans(n, OO);
    set<pair<int, int>> s;
    ans[n - 1] = 0;
    s.emplace(ans[n - 1], n - 1);
    while (!s.empty()) {
        int v = s.begin() -> second;
        s.erase(s.begin());
        for (auto& u : adj[v]) {
            roads[u]--;
            if (ans[v] + roads[u] + 1 < ans[u]) {
                s.erase({ans[u], u});
                ans[u] = ans[v] + roads[u] + 1;
                s.emplace(ans[u], u);
            }
        }
    }
    cout << ans[0];
}
