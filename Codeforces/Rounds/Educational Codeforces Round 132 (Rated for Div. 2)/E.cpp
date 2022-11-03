/**
 *    author:  MaGnsi0
 *    created: 25.07.2022 07:26:44
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
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int ans = 0;
    vector<set<int>> xor_tree(n);
    function<void(int, int, int)> dfs = [&](int v, int p, int cur_xor) {
        int large = v;
        xor_tree[v].insert(cur_xor ^ a[v]);
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            dfs(u, v, cur_xor ^ a[v]);
            if ((int)xor_tree[large].size() < (int)xor_tree[u].size()) {
                large = u;
            }
        }
        xor_tree[v].swap(xor_tree[large]);
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            for (auto& x : xor_tree[u]) {
                if (xor_tree[v].count(a[v] ^ x)) {
                    xor_tree[v].clear();
                    ans++;
                    return;
                }
            }
            for (auto& x : xor_tree[u]) {
                xor_tree[v].insert(x);
            }
        }
    };
    dfs(0, -1, 0);
    cout << ans;
}
