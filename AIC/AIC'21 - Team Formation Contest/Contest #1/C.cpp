/**
 *    author:  MaGnsi0
 *    created: 16/07/2021 13:24:48
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int dfs(vector<vector<int>>& adj, vector<int>& w, vector<int>& t, vector<int>& res, int val, int root, int v, int par = -1) {
    w[v] = t[v];
    for (auto& u : adj[v]) {
        if (u != par) {
            w[v] += dfs(adj, w, t, res, val, root, u, v);
        }
    }
    if (w[v] == val) {
        w[v] = 0;
        if (v != root) {
            res.push_back(v);
        }
    }
    return w[v];
}
 
int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, sum = 0, v;
    cin >> n;
    vector<int> t(n + 1), w(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1, j; i <= n; ++i) {
        cin >> j >> t[i];
        sum += t[i];
        if (!j) {
            v = i;
            continue;
        }
        adj[j].push_back(i);
    }
    if (sum % 3) {
        cout << -1;
        return 0;
    }
    vector<int> res;
    dfs(adj, w, t, res, sum / 3, v, v);
    if (res.size() < 2) {
        cout << -1;
    } else {
        cout << res[0] << " " << res[1];
    }
}
