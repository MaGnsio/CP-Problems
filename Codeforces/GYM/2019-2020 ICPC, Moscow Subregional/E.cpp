/**
 *    author:  MaGnsi0
 *    created: 28.09.2024 18:26:59
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<unordered_map<int, int>> d(n);
        vector<vector<tuple<int, int, int>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            int t; cin >> t;
            adj[u].emplace_back(v, t, 0);
            adj[v].emplace_back(u, t, 1);
            d[u][t] = d[v][t] = OO;
        }
        for (int i = 0; i < n; ++i) {
            sort(adj[i].begin(), adj[i].end(), [](tuple<int, int, int> x, tuple<int, int, int> y) {
                return get<1>(x) > get<1>(y);
            });
        }
        vector<int> I(n, 0);
        deque<tuple<int, int, int>> S;
        d[0][0] = 0; S.push_back(make_tuple(0, 0, 0));
        while (!S.empty()) {
            auto [d_v, v, lt] = S.front(); S.pop_front();
            if (d_v != d[v][lt]) { continue; }
            for (/*_*/ ; I[v] < (int)adj[v].size(); ++I[v]) {
                auto [u, t, w] = adj[v][I[v]];
                if (t <= lt) { break; }
                if (d[u][t] > d_v + w) {
                    d[u][t] = d_v + w;
                    if (w == 1) {
                        S.push_back(make_tuple(d[u][t], u, t));
                    } else {
                        S.push_front(make_tuple(d[u][t], u, t));
                    }
                }
            }
        }
        int ans = OO;
        for (auto [_, x] : d[n - 1]) {
            ans = min(ans, x);
        }
        cout << (ans == OO ? -1 : ans) << "\n";
    }
}

