/**
 *    author:  MaGnsi0
 *    created: 10.04.2022 22:32:36
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("time.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n), C(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> C[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        vector<int> ans(n);
        vector<ordered_multiset<int>> Times(n);
        function<void(int, int)> DFS = [&](int v, int p) {
            int large = -1;
            for (auto& u : adj[v]) {
                if (u == p) {
                    continue;
                }
                DFS(u, v);
                if (large == -1 || (int)Times[large].size() < (int)Times[u].size()) {
                    large = u;
                }
            }
            if (large == -1) {
                ans[v] = A[v];
                Times[v].insert(ans[v]);
                return;
            }
            Times[v].swap(Times[large]);
            for (auto& u : adj[v]) {
                if (u == p || u == large) {
                    continue;
                }
                for (auto& x : Times[u]) {
                    Times[v].insert(x);
                }
            }
            int k = (B[v]  * (int)Times[v].size() + 99) / 100;
            ans[v] = min(A[v], *Times[v].find_by_order(k - 1) + C[v]);
            Times[v].insert(ans[v]);
        };
        DFS(0, -1);
        sort(ans.begin(), ans.end());
        int Q;
        cin >> Q;
        for (int i = 0; i < Q; ++i) {
            int x;
            cin >> x;
            int l = 0, r = n - 1, res = 0;
            while (l <= r) {
                int m = (l + r) / 2;
                if (ans[m] <= x) {
                    res = m + 1;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            cout << res << "\n";
        }
    }
}
