/**
 *    author:  MaGnsi0
 *    created: 04.04.2023 04:48:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].emplace_back(v - 1);
        adj[v - 1].emplace_back(u - 1);
    }
    int m;
    cin >> m;
    vector<vector<pair<int, int>>> b(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        b[y - 1].emplace_back(x - 1, i);
    }
    vector<vector<array<int, 2>>> d(n, vector<array<int, 2>>(1, {-1, -1}));
    function<void(int, int)> add = [&](int j, int x) {
        int root = 0;
        for (int bit = 30; bit >= 0; --bit) {
            int k = ((x >> bit) & 1);
            if (d[j][root][k] == -1) {
                d[j][root][k] = (int)d[j].size(); 
                d[j].emplace_back(array<int, 2>{-1, -1});
            }
            root = d[j][root][k];
        }
    };
    function<int(int, int)> find_max = [&](int j, int x) {
        int root = 0, ans = 0;
        for (int bit = 30; bit >= 0; --bit) {
            int k = ((x >> bit) & 1);
            if (d[j][root][k ^ 1] != -1) {
                ans |= (1 << bit);
                root = d[j][root][k ^ 1];
            } else {
                assert(d[j][root][k] != -1);
                root = d[j][root][k];
            }
        }
        return ans;
    };
    function<void(int, int, int, int)> merge = [&](int i, int u, int j, int v) {
        for (int k = 0; k < 2; ++k) {
            if (d[i][u][k] == -1 && d[j][v][k] != -1) {
                d[i][u][k] = (int)d[i].size();
                d[i].emplace_back(array<int, 2>{-1, -1});
            }
            if (d[i][u][k] != -1 && d[j][v][k] != -1) {
                merge(i, d[i][u][k], j, d[j][v][k]);
            }
        }
    };
    vector<int> ans(m);
    function<void(int, int)> dfs = [&](int v, int p) {
        int big = v;
        for (int u : adj[v]) {
            if (u == p) { continue; }
            dfs(u, v);
            if ((int)d[u].size() >= (int)d[big].size()) {
                big = u;
            }
        }
        d[v].swap(d[big]);
        add(v, a[v]);
        for (auto& u : adj[v]) {
            if (u == p) { continue; }
            if (u == big) { continue; }
            merge(v, 0, u, 0);
        }
        for (auto& [u, j] : b[v]) {
            ans[j] = find_max(v, a[u]);
        }
    };
    dfs(0, -1);
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << "\n";
    }
}
