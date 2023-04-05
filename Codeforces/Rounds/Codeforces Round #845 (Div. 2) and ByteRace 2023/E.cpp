/**
 *    author:  MaGnsi0
 *    created: 24.01.2023 21:16:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> U(m), V(m), W(m), I(m);
        for (int i = 0; i < m; ++i) {
            cin >> U[i] >> V[i] >> W[i];
            U[i]--, V[i]--, I[i] = i;
        }
        sort(I.begin(), I.end(), [&](int i, int j) {
                return W[i] < W[j];
            });
        vector<int> top_sort;
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        function<void(int)> dfs = [&](int v) {
            visited[v] = true;
            for (auto& u : adj[v]) {
                if (!visited[u]) {
                    dfs(u);
                }
            }
            top_sort.push_back(v);
        };
        function<bool(int)> ok = [&](int x) {
            top_sort.clear();
            adj = vector<vector<int>>(n);
            visited = vector<bool>(n, false);
            for (int i = m - 1; i >= 0; --i) {
                int j = I[i];
                if (W[j] <= x) {
                    adj[U[j]].push_back(V[j]);
                    adj[V[j]].push_back(U[j]);
                } else {
                    adj[U[j]].push_back(V[j]);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    dfs(i);
                }
            }
            visited = vector<bool>(n, false);
            dfs(top_sort.back());
            return count(visited.begin(), visited.end(), true) == n;
        };
        int low = 0, high = W[I[m - 1]], ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ok(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
