/**
 *    author:  MaGnsi0
 *    created: 03.08.2023 21:47:22
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; ++v) {
        int u; cin >> u;
        adj[u - 1].push_back(v);
    }
    vector<int> h(n), ans(n), ans1(n), closest_leaf(n, n);
    function<void(int)> dfs = [&](int v) {
        if (adj[v].empty()) { //leaf node
            ans[v] = ans1[v] = 1;
            closest_leaf[v] = h[v];
            return;
        }
        for (int u : adj[v]) {
            h[u] = h[v] + 1; dfs(u);
            if (closest_leaf[u] - h[v] <= k) {
                ans1[v] += ans1[u];
            }
            closest_leaf[v] = min(closest_leaf[v], closest_leaf[u]);
        }
        ans[v] = ans1[v];
        for (int u : adj[v]) {
            if (closest_leaf[u] - h[v] <= k) {
                ans[v] = max(ans[v], ans1[v] - ans1[u] + ans[u]);
            } else {
                ans[v] = max(ans[v], ans1[v] + ans[u]);
            }
        }
    };
    dfs(0);
    cout << ans[0];
}
