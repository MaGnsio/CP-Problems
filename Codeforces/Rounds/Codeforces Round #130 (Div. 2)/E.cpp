/**
 *    author:  MaGnsi0
 *    created: 08.12.2021 20:55:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> roots;
    vector<vector<int>> adj(n);
    for (int u, v = 0; v < n; ++v) {
        cin >> u;
        if (!u) {
            roots.push_back(v);
            continue;
        }
        adj[u - 1].push_back(v);
    }
    int lg = 32 - __builtin_clz(n), t = 0;
    vector<vector<int>> depths(n), up(n, vector<int>(lg + 1));
    vector<int> depth(n, 0), tin(n, 0), tout(n, 0);
    {
        function<void(int, int, int)> dfs = [&](int v, int p, int d) {
            tin[v] = ++t;
            depth[v] = d;
            depths[d].push_back(v);
            up[v][0] = p;
            for (int i = 1; i <= lg; ++i) {
                up[v][i] = up[up[v][i - 1]][i - 1];
            }
            for (auto& u : adj[v]) {
                if (u != p) {
                    dfs(u, v, d + 1);
                }
            }
            tout[v] = ++t;
        };
        for (auto& x : roots) {
            dfs(x, x, 0);
        }
    }
    auto is_ancestor = [&](int u, int v) {
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    };
    auto Kth_ancestor = [&](int v, int k) {
        if (depth[v] < k) {
            return -1;
        }
        for (int i = 0; i <= lg; ++i) {
            if ((k >> i) & 1) {
                v = up[v][i];
            }
        }
        return v;
    };
    int q;
    cin >> q;
    while (q--) {
        int v, p;
        cin >> v >> p;
        v--;
        int Kth = Kth_ancestor(v, p);
        if (Kth == -1) {
            cout << 0 << " ";
            continue;
        }
        int l = 0, r = depths[depth[v]].size() - 1, left, right;
        while (l <= r) {
            int m = (l + r) / 2;
            if (tin[depths[depth[v]][m]] >= tin[Kth]) {
                left = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        l = 0, r = depths[depth[v]].size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (tout[depths[depth[v]][m]] <= tout[Kth]) {
                right = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << right - left << " ";
    }
}
