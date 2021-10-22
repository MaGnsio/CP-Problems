#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, e = 0;
    cin >> n >> m;
    vector<int> head(n, -1), next(m, -1), to(m, 0);
    auto addEdge = [&](int u, int v) {
        to[e] = v;
        next[e] = head[u];
        head[u] = e++;
    };
    auto addBiEdge = [&](int u, int v) {
        //edge[i] and edge[i ^ 1]
        addEdge(u, v);
        addEdge(v, u);
    };
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        addBiEdge(u, v);
    }
}
