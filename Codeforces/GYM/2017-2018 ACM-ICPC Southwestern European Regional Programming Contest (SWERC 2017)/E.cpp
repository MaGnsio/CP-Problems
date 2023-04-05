/**
 *    author:  MaGnsi0
 *    created: 13.11.2022 21:30:40
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e12;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t m, n;
    cin >> m >> n;
    if (n == 0) {
        cout << 0 << "\n" << 0;
        return 0;
    }
    map<string, bool> is_base;
    map<string, vector<tuple<string, int64_t, int64_t>>> adj;
    for (int i = 0; i < n; ++i) {
        int64_t c, p;
        string x, y, z;
        cin >> x >> y >> z >> c >> p;
        is_base[x] = false;
        if (is_base.count(y) == 0) {
            is_base[y] = true;
        }
        adj[y].emplace_back(x, c, p);
    }
    if (m == 0) {
        cout << 0 << "\n" << 0;
        return 0;
    }
    int cnt = 0;
    map<string, int> id;
    for (auto& [x, _] : is_base) {
        id[x] = cnt++;
    }
    vector<pair<int64_t, int64_t>> a(cnt, {OO, OO});
    queue<int> q;
    for (auto& [x, ok] : is_base) {
        if (ok) {
            a[id[x]] = {0, 0};
            q.push(id[x]);
        }
    }
    vector<vector<tuple<int, int64_t, int64_t>>> adjx(cnt);
    for (auto& [x, y] : adj) {
        for (auto& [i, j, k] : y) {
            adjx[id[x]].emplace_back(id[i], j, k);
        }
    }
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (auto& [x, y, z] : adjx[s]) {
            int nc = a[s].first + y;
            int np = a[s].second + z;
            if ((nc < a[x].first) || (nc == a[x].first && np > a[x].second)) {
                a[x] = {nc, np};
                q.push(x);
            }
        }
    }
    vector<int64_t> dp(m + 1, 0);
    if (a[0].first <= m) {
        dp[a[0].first] = a[0].second;
    }
    for (int i = 1; i < cnt; ++i) {
        for (int j = m - a[i].first; j >= 0; --j) {
            dp[a[i].first + j] = max(dp[j] + a[i].second, dp[a[i].first + j]);
        }
    }
    int64_t cost = 0, prestige = 0;
    for (int i = 1; i <= m; ++i) {
        if (dp[i] > prestige) {
            cost = i;
            prestige = dp[i];
        }
    }
    cout << prestige << "\n" << cost;
}
