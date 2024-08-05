/**
 *    author:  MaGnsi0
 *    created: 13.07.2024 20:59:38
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e17;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n), b(n), d(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n);
        for (int v = 1; v < n; ++v) {
            int u; cin >> u; u--;
            d[v] = d[u] + 1;
            adj[u].push_back(v);
        }
        for (int v = 0; v < n; ++v) {
            if (adj[v].empty()) {
                b[v] = OO;
            } else {
                b[v] = -a[v];
                for (int u : adj[v]) {
                    b[v] += a[u];
                }
            }
        }
        int64_t ans = 0;
        for (int v = n - 1; v >= 0; --v) {
            queue<int> Q; Q.push(v);
            while (!Q.empty()) {
                int k = Q.front(); Q.pop();
                for (int u : adj[k]) {
                    int64_t add = min(-b[v], b[u]);
                    assert(b[u] >= 0);
                    if (add >= 0) {
                        b[v] += add;
                        b[u] -= add;
                        ans += (d[u] - d[v]) * add;
                        Q.push(u);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
