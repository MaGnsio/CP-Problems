/**
 *    author:  MaGnsi0
 *    created: 21/06/2021 02:41:31
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    struct edge {
        int u, v, w;
    };
    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    vector<int> d(n + 1, 30000);
    d[1] = 0;
    for (;;) {
        bool any = false;
        for (auto& [u, v, w] : edges) {
            if (d[u] < 30000) {
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    any = true;
                }
            }
        }
        if (!any) {
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << " ";
    }
}
