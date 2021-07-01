/**
 *    author:  MaGnsi0
 *    created: 08/06/2021 15:42:52
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, s, e;
    cin >> n >> s >> e;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int v = 1; v <= n; ++v) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; ++i) {
            int u;
            cin >> u;
            if (i == 1) {
                adj[v].push_back({u, 0});
            } else {
                adj[v].push_back({u, 1});
            }
        }
    }
    vector<int> d(n + 1, INT_MAX);
    deque<int> q;
    d[s] = 0;
    q.push_front(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto& [u, w] : adj[v]) {
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1) {
                    q.push_back(u);
                } else {
                    q.push_front(u);
                }
            }
        }
    }
    cout << (d[e] == INT_MAX ? -1 : d[e]);
}
