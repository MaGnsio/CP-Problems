/**
 *    author:  MaGnsi0
 *    created: 20.02.2022 16:26:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), c(m);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--, c[i]--;
        adj[b[i]].push_back(c[i]);
        adj[c[i]].push_back(b[i]);
    }
    vector<int> color(n, -1);
    vector<bool> visited(n, false);
    function<bool(int, int)> bipartite = [&](int v, int c) {
        color[v] = c;
        visited[v] = true;
        for (auto& u : adj[v]) {
            if (visited[u] && color[u] == color[v]) {
                return false;
            }
            if (!visited[u] && !bipartite(u, c ^ 1)) {
                return false;
            }
        }
        return true;
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && !bipartite(i, 0)) {
            cout << "NO";
            return 0;
        }
    }
    adj = vector<vector<int>>(n);
    for (int i = 0; i < m; ++i) {
        if (color[b[i]]) {
            swap(b[i], c[i]);
        }
        if (a[i]) {
            adj[c[i]].push_back(b[i]);
        } else {
            adj[b[i]].push_back(c[i]);
        }
    }
    function<bool(int)> cycle = [&](int v) {
        color[v] = 1;
        for (auto& u : adj[v]) {
            if (color[u] == 2) {
                continue;
            }
            if (color[u] == 1) {
                return true;
            }
            if (cycle(u)) {
                return true;
            }
        }
        color[v] = 2;
        return false;
    };
    vector<char> direction(n);
    for (int i = 0; i < n; ++i) {
        direction[i] = (color[i] ? 'R' : 'L');
    }
    color = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!color[i] && cycle(i)) {
            cout << "NO";
            return 0;
        }
    }
    vector<int> topsort;
    function<void(int)> tsort = [&](int v) {
        visited[v] = true;
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                tsort(u);
            }
        }
        topsort.push_back(v);
    };
    visited = vector<bool>(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            tsort(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
    vector<int> position(n);
    for (int i = 0; i < n; ++i) {
        position[topsort[i]] = i;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << direction[i] << " " << position[i] << "\n";
    }
} 
