/**
 *    author:  MaGnsi0
 *    created: 06.11.2023 12:30:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i]; a[i]--;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i]; b[i]--;
    }
    vector<set<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        adj[a[i]].insert(b[i]);
        adj[b[i]].insert(a[i]);
    }
    vector<int> color(n, -1);
    function<void(int, int)> dfs = [&](int v, int c) {
        color[v] = c;
        for (int u : adj[v]) {
            if (color[u] == -1) { dfs(u, c ^ 1); }
            if (color[u] == color[v]) {
                cout << "No";
                exit(0);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (color[i] != -1) { continue; }
        dfs(i, 0);
    }
    cout << "Yes";
}
