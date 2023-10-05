/**
 *    author:  MaGnsi0
 *    created: 06.09.2023 03:38:58
**/
#include <bits/stdc++.h>

using namespace std;

struct union_find {
    int comps;
    map<int, int> parent, length;
    union_find(int n) { comps = n; }
    int find(int x) {
        if (parent.count(x) == 0) { parent[x] = x; }
        if (parent[x] != x) { parent[x] = find(parent[x]); }
        return parent[x];
    }
    void unite(int x, int y) {
        int Px = find(x);
        int Py = find(y);
        if (Px == Py) { return; }
        if (length.count(Px) == 0) { length[Px] = 1; }
        if (length.count(Py) == 0) { length[Py] = 1; }
        if (length[Px] < length[Py]) { swap(Px, Py); }
        parent[Py] = Px, length[Px] += length[Py]; comps--;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; ++v) {
        int u; cin >> u; u--;
        adj[u].push_back(v);
    }
    vector<int> U(n), V(n);
    for (int i = 0; i < n; ++i) {
        cin >> U[i]; U[i]--;
        cin >> V[i]; V[i]--;
    }
    vector<int> ans(n, -1);
    vector<union_find> a(n, union_find(k));
    vector<vector<pair<int, int>>> b(n);
    function<void(int)> dfs = [&](int v) {
        int large = -1, m = 0;
        for (int u : adj[v]) {
            dfs(u);
            int x = (int)b[u].size();
            if (m <= x) {
                large = u, m = x;
            }
        }
        if (large == -1) {
            if (U[v] != -1) {
                a[v].unite(U[v], V[v]);
                b[v].emplace_back(U[v], V[v]);
            }
            ans[v] = a[v].comps;
            return;
        }
        swap(a[v].comps, a[large].comps);
        a[v].length.swap(a[large].length);
        a[v].parent.swap(a[large].parent);
        b[v].swap(b[large]);
        for (int u : adj[v]) {
            if (u == large) { continue; }
            for (auto [x, y] : b[u]) {
                a[v].unite(x, y);
                b[v].emplace_back(x, y);
            }
        }
        if (U[v] != -1) {
            a[v].unite(U[v], V[v]);
            b[v].emplace_back(U[v], V[v]);
        }
        ans[v] = a[v].comps;
    };
    dfs(0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
}
