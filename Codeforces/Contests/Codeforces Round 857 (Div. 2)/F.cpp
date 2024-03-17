/**
 *    author:  MaGnsi0
 *    created: 04.01.2024 19:45:23
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e17;

bool better(pair<int64_t, int64_t> x, pair<int64_t, int64_t> y) {
    if (x.first < y.first) { return true; }
    if (x.first > y.first) { return false; }
    return x.second > y.second;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int64_t p; cin >> p;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<pair<int, int64_t>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            int64_t w; cin >> w;
            adj[u].emplace_back(v, w);
        }
        set<tuple<int64_t, int64_t, int, int>> S;
        vector<vector<pair<int64_t, int64_t>>> ans(n, vector<pair<int64_t, int64_t>>(n, {OO, 0}));
        ans[0][0] = make_pair(0, p);
        S.emplace(0, -p, 0, 0);
        while (!S.empty()) {
            auto [dances, cost, v, best] = *S.begin();
            S.erase(S.begin()); cost *= -1;
            if (ans[v][best] != make_pair(dances, cost)) { continue; }
            for (auto [u, w] : adj[v]) {
                int64_t new_best = (a[best] > a[u] ? best : u);
                int64_t extra_dances = (w > cost ? (w - cost + a[best] - 1) / a[best] : 0);
                int64_t new_cost = cost + extra_dances * a[best] - w;
                if (better(make_pair(dances + extra_dances, new_cost), ans[u][new_best])) {
                    ans[u][new_best] = make_pair(dances + extra_dances, new_cost);
                    S.emplace(dances + extra_dances, -new_cost, u, new_best);
                }
            }
        }
        int64_t min_dances = OO;
        for (int i = 0; i < n; ++i) {
            min_dances = min(min_dances, ans[n - 1][i].first);
        }
        cout << (min_dances == OO ? -1 : min_dances) << "\n";
    }
}
