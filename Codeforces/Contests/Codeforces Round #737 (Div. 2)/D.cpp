/**
 *    author:  MaGnsi0
 *    created: 09/08/2021 17:09:06
**/
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& g, vector<int>& d, vector<int>& par, int v) {
    d[v] = 1;
    for (auto& u : g[v]) {
        if (d[u] == -1) {
            dfs(g, d, par, u);
        }
        if (d[u] + 1 > d[v]) {
            d[v] = d[u] + 1;
            par[v] = u;
        }
    }
    return d[v];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p;
    for (int i = 0; i < m; i++) {
        int r, c1, c2;
        cin >> r >> c1 >> c2;
        --r; --c1; --c2;
        p.emplace_back(c1, r);
        p.emplace_back(c2 + 1, ~r);
    }
    sort(p.begin(), p.end());
    vector<vector<int>> g(n);
    map<int, int> mp;
    int beg = 0;
    while (beg < (int) p.size()) {
        int end = beg;
        while (end + 1 < (int) p.size() && p[end + 1].first == p[end].first) {
            ++end;
        }
        for (int i = beg; i <= end; i++) {
            int id = p[i].second;
            if (id >= 0) {
                auto it = mp.lower_bound(id);
                if (it != mp.end() && it->first == id) {
                    it->second += 1;
                    continue;
                }
                if (it != mp.begin()) {
                    int x = prev(it)->first;
                    g[x].push_back(id);
                }
                if (it != mp.end()) {
                    int y = it->first;
                    g[id].push_back(y);
                }
                mp[id] = 1;
            } else {
                id = ~id;
                auto it = mp.find(id);
                assert(it != mp.end());
                if (it->second > 1) {
                    it->second -= 1;
                    continue;
                }
                if (it != mp.begin() && next(it) != mp.end()) {
                    int x = prev(it)->first;
                    int y = next(it)->first;
                    g[x].push_back(y);
                }
                mp.erase(it);
            }
        }
        beg = end + 1;
    }
    vector<int> d(n, -1), par(n, -1);
    for (int i = 0; i < n; ++i) {
        if (d[i] == -1) {
            dfs(g, d, par, i);
        }
    }
    int ans = INT_MAX, idx = 0;
    for (int i = 0; i < n; ++i) {
        if (n - d[i] < ans) {
            ans = n - d[i];
            idx = i;
        }
    }
    vector<int> del(n, 1);
    for (int v = idx; v != -1; v = par[v]) {
        del[v] = 0;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        if (del[i]) {
            cout << i + 1 << " ";
        }
    }
}
