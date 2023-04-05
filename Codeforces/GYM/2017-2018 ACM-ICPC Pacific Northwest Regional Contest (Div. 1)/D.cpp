/**
 *    author:  MaGnsi0
 *    created: 08.11.2022 22:05:10
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u - 1].emplace_back(v - 1, c);
        adj[v - 1].emplace_back(u - 1, c);
    }
    vector<bool> good(n, true);
    function<void(int, int, int)> dfs = [&](int v, int p, int c) {
        for (auto& [u, w] : adj[v]) {
            if (u == p) {
                continue;
            }
            good[v] = good[v] && (w != c);
            dfs(u, v, w);
        }
    };
    dfs(0, -1, -1);
    vector<bool> dp(n, true);
    function<bool(int, int)> solve = [&](int v, int p) {
        for (auto& [u, w] : adj[v]) {
            if (u == p) {
                continue;
            }
            bool x = solve(u, v);
            dp[v] = dp[v] && x;
        }
        return (dp[v] && good[v]);
    };
    solve(0, -1);
    vector<bool> ans(n, false);
    function<void(int, int)> go = [&](int v, int p) {
        ans[v] = dp[v];
        int m = (int)adj[v].size();
        if (m == 0) {
            return;
        }
        vector<bool> pre(m), suf(m), preg(m), sufg(m);
        pre[0] = dp[adj[v][0].first];
        preg[0] = good[adj[v][0].first];
        for (int i = 1; i < m; ++i) {
            pre[i] = pre[i - 1] && dp[adj[v][i].first];
            preg[i] = preg[i - 1] && good[adj[v][i].first];
        }
        suf[m - 1] = dp[adj[v][m - 1].first];
        sufg[m - 1] = good[adj[v][m - 1].first];
        for (int i = m - 2; i >= 0; --i) {
            suf[i] = suf[i + 1] && dp[adj[v][i].first];
            sufg[i] = sufg[i + 1] && good[adj[v][i].first];
        }
        multiset<int> colors;
        for (int i = 0; i < m; ++i) {
            colors.insert(adj[v][i].second);
        }
        for (int i = 0; i < m; ++i) {
            int u = adj[v][i].first;
            int c = adj[v][i].second;
            if (u == p) {
                continue;
            }
            bool oldu = dp[u];
            bool oldv = dp[v];
            bool oldg = good[v];
            bool L = (i ? pre[i - 1] : true);
            bool R = (i + 1 < m ? suf[i + 1] : true);
            bool l = (i ? preg[i - 1] : true);
            bool r = (i + 1 < m ? sufg[i + 1] : true);
            dp[u] = oldu && L && R && l && r && (colors.count(c) < 2);
            dp[v] = L && R && l && r;
            good[v] = colors.count(c) < 2;
            go(u, v);
            dp[u] = oldu;
            dp[v] = oldv;
            good[v] = oldg;
        }
    };
    go(0, -1);
    int m = count(ans.begin(), ans.end(), true);
    cout << m << "\n";
    for (int i = 0; i < n; ++i) {
        if (ans[i]) {
            cout << i + 1 << "\n";
        }
    }
}
