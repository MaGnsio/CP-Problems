/**
 *    author:  MaGnsi0
 *    created: 30/09/2021 23:49:14
**/
#include <bits/stdc++.h>
using namespace std;

int dfs1(vector<vector<int>>& adj, vector<int>& sub_tree, vector<int>& depth, int d, int v, int par = -1) {
    sub_tree[v] = 1;
    depth[v] = d;
    for (auto& u : adj[v]) {
        if (u != par) {
            sub_tree[v] += dfs1(adj, sub_tree, depth, d + 1, u, v);
        }
    }
    return sub_tree[v];
}

void dfs2(vector<vector<int>>& adj, vector<int>& parent, vector<int>& p, vector<int>& h, int cur_happiness, int v) {
    if (!p[v]) {
        h[v] = cur_happiness;
    } else {
        cur_happiness++;
    }
    for (auto& u : adj[v]) {
        if (u == parent[v]) {
            continue;
        }
        dfs2(adj, parent, p, h, cur_happiness, u);
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sub_tree(n, 0), depth(n, 0);
    {
        dfs1(adj, sub_tree, depth, 0, 0);
        assert(sub_tree[0] == n);
    }
    vector<int> best, parent(n, -1);
    priority_queue<pair<int, int>> q;
    {
        q.push({sub_tree[0] - depth[0], 0});
        while (!q.empty()) {
            int v = q.top().second;
            best.push_back(v);
            q.pop();
            for (auto& u : adj[v]) {
                if (u == parent[v]) {
                    continue;
                }
                q.push({sub_tree[u] - depth[u], u});
                parent[u] = v;
            }
        }
        assert((int)best.size() == n);
    }
    vector<int> p(n, 0);
    {
        for (int i = 0; i < n - k; ++i) {
            p[best[i]] = 1;
        }
    }
    vector<int> h(n, 0);
    {
        dfs2(adj, parent, p, h, 0, 0);
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += (long long)h[i];
    }
    cout << res;
}
