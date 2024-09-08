/**
 *    author:  MaGnsi0
 *    created: 08.09.2024 21:26:52
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<tuple<int, int, int, int, int>> events;
    events.emplace_back(-1, -1, INT_MAX, 0, 0);
    events.emplace_back(INT_MAX, -1, INT_MAX, 0, 1);
    for (int i = 1; i <= n; ++i) {
        int x1; cin >> x1;
        int y1; cin >> y1;
        int x2; cin >> x2;
        int y2; cin >> y2;
        events.emplace_back(x1, y1, y2, i, 0); 
        events.emplace_back(x2, y1, y2, i, 1);
    }
    for (int i = n + 1; i <= n + m; ++i) {
        int x; cin >> x;
        int y; cin >> y;
        events.emplace_back(x, y, y, i, 0);
        events.emplace_back(x, y, y, i, 1);
    }
    sort(events.begin(), events.end());
    vector<vector<int>> adj(n + m + 1);
    map<int, int> mp;
    for (auto [x, y1, y2, i, t] : events) {
        if (t == 1) {
            mp.erase(y1);
            mp.erase(y2);
        } else {
            if (i == 0) {
                mp[y1] = mp[y2] = 0;
                continue;
            }
            auto it = prev(mp.upper_bound(y1));
            int j = it -> second;
            adj[j].push_back(i);
            mp[y1] = i; mp[y2] = j;
        }
    }
    int64_t distance_sum = 0;
    vector<int64_t> sum(n + m + 1, 0), count(n + m + 1, 0);
    function<void(int)> dfs = [&](int v) {
        if (adj[v].empty()) {
            sum[v] = 0, count[v] = n < v && v <= n + m;
            return;
        }
        for (int u : adj[v]) {
            dfs(u);
            sum[v] += sum[u] + count[u];
            count[v] += count[u];
            distance_sum -= count[u] * (sum[u] + count[u]);
        }
        distance_sum += count[v] * sum[v];
        return;
    };
    dfs(0);
    int64_t total = 2LL * distance_sum - 2LL * m * (m - 1);
    double ans = 1.0 * total / (1LL * m * m);
    cout << fixed << setprecision(9) << ans;
}
