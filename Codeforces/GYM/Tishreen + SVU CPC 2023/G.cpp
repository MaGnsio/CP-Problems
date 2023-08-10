/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 08:16:15
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
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
        int ans = 0, val = 0;
        ordered_set<pair<int, int>> s;
        function<void(int)> add = [&](int v) {
            if (a[v] < 0) { return; }
            if ((int)s.size() < k) {
                val += a[v];
                s.insert({-a[v], v});
            } else {
                int x = -(s.find_by_order(k - 1) -> first);
                if (x < a[v]) {
                    val -= x;
                    val += a[v];
                }
                s.insert({-a[v], v});
            }
        };
        function<void(int)> remove = [&](int v) {
            if (a[v] < 0) { return; }
            int j = s.order_of_key({-a[v], v});
            if (j < k) {
                val -= a[v];
                s.erase({-a[v], v});
                if ((int)s.size() >= k) {
                    val += -(s.find_by_order(k - 1) -> first);
                }
            } else {
                s.erase({-a[v], v});
            }
        };
        function<void(int, int, int)> dfs = [&](int v, int p, int d) {
            if (d > m) { return; }
            add(v);
            ans = max(ans, val);
            for (int u : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v, d + 1);
            }
            remove(v);
        };
        for (int i = 0; i < n; ++i) {
            dfs(i, -1, 1);
        }
        cout << ans << "\n";
    }
}
