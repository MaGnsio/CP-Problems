/**
 *    author:  MaGnsi0
 *    created: 22/06/2021 03:30:54
**/
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    while ((cin >> n) && (n != -1)) {
        vector<int> energy(n + 1);
        vector<edge> edges;
        for (int u = 1; u <= n; ++u) {
            int m;
            cin >> energy[u] >> m;
            energy[u] *= -1;
            for (int i = 0; i < m; ++i) {
                int v;
                cin >> v;
                edges.push_back({u, v, 0});
            }
        }
        for (auto& [u, v, w] : edges) {
            w = energy[v];
        }
        vector<int> d(n + 1, INT_MAX);
        d[1] = -100;
        for (int i = 0; i < 100000; ++i) { //care for (0 --> negative cycle --> postive cycle --> n)
            for (auto& [u, v, w] : edges) {
                if (d[u] < INT_MAX) {
                    if (d[u] + w < 0) {
                        if (d[u] + w < d[v]) {
                            d[v] = d[u] + w;
                        }
                    }
                }
            }
        }
        cout << (d[n] < 0 ? "winnable\n" : "hopeless\n");
    }
}
