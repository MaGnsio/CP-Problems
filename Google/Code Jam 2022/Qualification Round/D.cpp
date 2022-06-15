/**
 *    author:  MaGnsi0
 *    created: 02.04.2022 01:48:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int> F(n), P(n);
        for (int i = 0; i < n; ++i) {
            cin >> F[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> P[i];
        }
        vector<int> deg(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (P[i] == 0) {
                continue;
            }
            adj[i].push_back(P[i] - 1);
            deg[P[i] - 1]++;
        }
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        vector<bool> visited(n, false), is_leaf(n, true);
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0) {
                visited[i] = true;
                q.push({F[i], i});
            }
        }
        while (!q.empty()) {
            int v = q.top().second, ans_v = q.top().first;
            q.pop();
            if (ans_v != F[v]) {
                continue;
            }
            for (auto& u : adj[v]) {
                if (!visited[u]) {
                    F[u] = max(F[v], F[u]);
                    visited[u] = true;
                    q.push({F[u], u});
                    is_leaf[v] = false;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * (is_leaf[i] * F[i]);
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
