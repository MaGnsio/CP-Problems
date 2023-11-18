/**
 *    author:  MaGnsi0
 *    created: 27.09.2023 19:16:48
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 2e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u - 1].emplace_back(v - 1, c);
        adj[v - 1].emplace_back(u - 1, c);
    }
    function<pair<vector<int>, vector<int>>(int)> S = [&](int source) {
        vector<int> ans(n, OO), p(n, -1), patch;
        vector<bool> patched(n, false);
        patched[source] = true;
        patch.push_back(source);
        while (!patch.empty()) {
            set<int> to_patch;
            for (int v : patch) {
                for (auto [u, c] : adj[v]) {
                    if (patched[u]) { continue; }
                    if (ans[u] > min(ans[v], c)) { p[u] = v; }
                    ans[u] = min(ans[u], min(ans[v], c));
                    to_patch.insert(u);
                }
            }
            patch.clear();
            for (int u : to_patch) {
                patched[u] = true;
                patch.push_back(u);
            }
        }
        return make_pair(ans, p);
    };
    function<vector<int>(int)> D = [&](int source) {
        vector<int> ans(n, OO);
        queue<int> Q;
        ans[source] = 0;
        Q.push(source);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (auto [u, _] : adj[v]) {
                if (ans[v] + 1 < ans[u]) {
                    ans[u] = ans[v] + 1;
                    Q.push(u);
                }
            }
        }
        return ans;
    };
    int diff = 0, f = 0, s = n - 1;
    vector<vector<int>> a(2), b(2), p(2);
    a[0] = D(0), a[1] = D(n - 1);
    tie(b[0], p[0]) = S(0);
    tie(b[1], p[1]) = S(n - 1);
    for (int v = 0; v < n; ++v) {
        for (auto [u, c] : adj[v]) {
            if (a[0][v] + 1 + a[1][u] != a[0][n - 1]) {
                continue;
            }
            int val = c - min(b[0][v], b[1][u]);
            if (diff < val) {
                diff = val;
                f = v;
                s = u;
            }
        }
    }
    vector<int> path;
    for (int v = f; v != -1; v = p[0][v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int v = s; v != -1; v = p[1][v]) {
        path.push_back(v);
    }
    cout << (int)path.size() - 1 << "\n";
    for (int v : path) {
        cout << v + 1 << " ";
    }
}
