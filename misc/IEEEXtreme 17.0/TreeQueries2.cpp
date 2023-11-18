/**
 *    author:  MaGnsi0
 *    created: 29.10.2023 01:13:42
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> U(n - 1), V(n - 1), W(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> U[i]; U[i]--;
        cin >> V[i]; V[i]--;
        cin >> W[i];
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x; x--;
            int v; cin >> v;
            a[x] = v;
        } else {
            int x; cin >> x; x--;
            int v; cin >> v;
            W[x] = v;
        }
        vector<vector<pair<int, int64_t>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            adj[U[i]].emplace_back(V[i], W[i]);
            adj[V[i]].emplace_back(U[i], W[i]);
        }
        int64_t ans = 0;
        function<void(int, int, int)> dfs = [&](int v, int p, int64_t sum) {
            ans += sum;
            for (auto [u, w] : adj[v]) {
                if (a[v] <= a[u]) {
                    dfs(v, u, sum * w % MOD);
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            dfs(i, -1, 1);
        }
        cout << ans << "\n";
    }
}
