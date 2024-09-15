/**
 *    author:  MaGnsi0
 *    created: 06.01.2024 14:28:34
**/
#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, length;
    union_find(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(n, 1);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int Px = find(x);
        int Py = find(y);
        if (Px == Py) {
            return;
        }
        if (length[Px] < length[Py]) {
            swap(Px, Py);
        }
        parent[Py] = Px;
        length[Px] += length[Py];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    union_find dsu(n);
    vector<pair<int, int>> edges;
    vector<set<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        if (a[u] == a[v]) {
            dsu.unite(u, v);
        } else {
            edges.emplace_back(u, v);
        }
    }
    vector<int> I(n);
    for (int i = 0; i < n; ++i) {
        I[i] = dsu.find(i);
    }
    for (auto& [u, v] : edges) {
        u = I[u];
        v = I[v];
        assert(a[u] != a[v]);
        if (a[u] < a[v]) {
            adj[u].emplace(v);
        } else {
            adj[v].emplace(u);
        }
    }
    vector<int> ans(n, 0);
    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> S;
    ans[I[0]] = -1; S.emplace(a[I[0]], -1, I[0]);
    while (!S.empty()) {
        auto [_, dv, v] = S.top();
        S.pop();
        if (dv != ans[v]) { continue; }
        for (int u : adj[v]) {
            if (ans[v] - 1 < ans[u]) {
                ans[u] = ans[v] - 1;
                S.emplace(a[u], ans[u], u);
            }
        }
    }
    cout << -1 * ans[I[n - 1]];
}
