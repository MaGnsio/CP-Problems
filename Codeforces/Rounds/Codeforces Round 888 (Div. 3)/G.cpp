/**
 *    author:  MaGnsi0
 *    created: 26.07.2023 10:11:32
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
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        int k;
        cin >> k;
        vector<int> a(k), b(k), e(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i] >> b[i] >> e[i];
            a[i]--, b[i]--;
        }
        vector<tuple<int, int, int>> c(n + k);
        for (int i = 0; i < n; ++i) {
            c[i] = make_tuple(h[i], 0, i);
        }
        for (int i = 0; i < k; ++i) {
            c[n + i] = make_tuple(e[i] + h[a[i]], 1, i);
        }
        sort(c.begin(), c.end());
        union_find d(n);
        vector<int> ans(k);
        vector<bool> used(n);
        for (auto [h, t, v] : c) {
            if (t == 1) {
                ans[v] = d.find(a[v]) == d.find(b[v]);
            } else {
                used[v] = true;
                for (int u : adj[v]) {
                    if (used[u]) {
                        d.unite(u, v);
                    }
                }
            }
        }
        for (int i = 0; i < k; ++i) {
            cout << (ans[i] ? "YES" : "NO") << "\n";
        }
    }
}
