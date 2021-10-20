/**
 *    author:  MaGnsi0
 *    created: 09/06/2021 17:18:50
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }
    vector<int> d(n + 1, INT_MAX);
    deque<int> q;
    q.push_front(1);
    d[1] = 0;
    while (!q.empty()) {
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
    if (d[n] == INT_MAX) {
        printf("%d", -1);
    } else {
        printf("%d", d[n]);
    }
}
