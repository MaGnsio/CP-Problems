/**
 *    author:  MaGnsi0
 *    created: 21/06/2021 20:07:29
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        struct edge {
            int u, v, w;
        };
        vector<edge> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
        bool ok;
        vector<int> d(n, 0);
        for (int i = 0; i < n; ++i) {
            ok = false;
            for (auto& [u, v, w] : edges) {
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    ok = true;
                }
            }
        }
        cout << (ok ? "possible\n" : "not possible\n");
    }
}
