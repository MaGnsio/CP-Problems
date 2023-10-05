/**
 *    author:  MaGnsi0
 *    created: 02.04.2023 17:54:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
        mp[{u - 1, v - 1}] = mp[{v - 1, u - 1}] = i;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
    }
    int max_ans = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[a[i]] >= 2) {
            max_ans = max(max_ans, a[i]);
        }
    }
    vector<int> ans(n - 1, max_ans);
    if (cnt[max_ans] == 2) {
        int x = -1, y = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == max_ans) {
                if (x == -1) {
                    x = i;
                } else {
                    y = i;
                }
            }
        }
        vector<int> p(n, -1);
        function<void(int)> dfs = [&](int v) {
            for (int u : adj[v]) {
                if (u == p[v]) { continue; }
                p[u] = v; dfs(u);
            }
        };
        dfs(x);
        int cur_v = y;
        vector<int> path;
        while (cur_v != -1) {
            path.push_back(cur_v);
            cur_v = p[cur_v];
        }
        int m = (int)path.size();
        vector<map<int, int>> good(2), bad(2);
        function<void(int, int, int, int)> add = [&](int v, int p, int j, int blocked) {
            if (bad[j].count(a[v])) {
                bad[j].erase(a[v]);
                good[j][a[v]] += 2;
            } else if (good[j].count(a[v])) {
                good[j][a[v]]++;
            } else {
                bad[j][a[v]]++;
            }
            for (int u : adj[v]) {
                if (u == p) { continue; }
                if (mp[{u, v}] == blocked) { continue; }
                add(u, v, j, blocked);
            }
        };
        function<void(int, int, int, int)> remove = [&](int v, int p, int j, int blocked) {
            if (bad[j].count(a[v])) {
                bad[j].erase(a[v]);
            } else if (good[j][a[v]] > 2) {
                good[j][a[v]]--;
            } else {
                good[j].erase(a[v]);
                bad[j][a[v]]++;
            }
            for (int u : adj[v]) {
                if (u == p) { continue; }
                if (mp[{u, v}] == blocked) { continue; }
                remove(u, v, j, blocked);
            }
        };
        set<int> blocked;
        add(x, -1, 0, mp[{path[0], path[1]}]);
        blocked.clear();
        add(y, path[1], 1, -1);
        for (int i = 1; i < m; ++i) {
            int u = path[i - 1], v = path[i], j = mp[{u, v}];
            int ans_tree1 = (good[0].empty() ? 0 : good[0].rbegin() -> first);
            int ans_tree2 = (good[1].empty() ? 0 : good[1].rbegin() -> first);
            ans[j] = max(ans_tree1, ans_tree2);
            if (v == x) { break; }
            add(v, u, 1, mp[{v, path[i + 1]}]);
            remove(v, u, 0, mp[{v, path[i + 1]}]);
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << ans[i] << "\n";
    }
}
