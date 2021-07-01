/**
 *    author:  MaGnsi0
 *    created: 09/06/2021 23:42:21
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, long long>>>& adj, int& s, long long& length, int v, int par = -1, long long cur = 0) {
    if (cur > length) {
        length = cur;
        s = v;
    }
    for (auto& [u, w] : adj[v]) {
        if (u == par) {
            continue;
        }
        dfs(adj, s, length, u, v, cur + w);
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int s;
    long long length = LLONG_MIN;
    dfs(adj, s, length, 1);
    length = INT_MIN;
    dfs(adj, s, length, s);
    cout << length;
}
