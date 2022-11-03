/**
 *    author:  MaGnsi0
 *    created: 19/06/2021 13:56:51
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<set<int>>& adj, vector<bool>& visited, int& cnt, int v) {
    visited[v] = true;
    cnt++;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs(adj, visited, cnt, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m = INT_MIN, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        m = max(m, v[i]);
    }
    vector<set<int>> adj(m + 1);
    for (int i = 0; i < n / 2; ++i) {
        if (v[i] != v[n - i - 1]) {
            adj[v[i]].insert(v[n - i - 1]);
            adj[v[n - i - 1]].insert(v[i]);
        }
    }
    vector<bool> visited(m + 1, false);
    for (int i = 1; i <= m; ++i) {
        if (!visited[i]) {
            int cnt = 0;
            dfs(adj, visited, cnt, i);
            ans += cnt - 1;
        }
    }
    cout << ans;
}
