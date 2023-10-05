/**
 *    author:  MaGnsi0
 *    created: 01.07.2023 00:55:24
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 20;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    string s; cin >> s;
    vector<int64_t> length(n), is_centroid(n), ans(n, 1), cnt(1 << M, 0);
    function<void(int, int)> dfs = [&](int v, int p) {
        length[v] = 1;
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            dfs(u, v);
            length[v] += length[u];
        }
    };
    function<int(int, int, int)> get_centroid = [&](int v, int p, int m) {
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            if (2 * length[u] > m) { return get_centroid(u, v, m); }
        }
        return v;
    };
    function<int64_t(int, int, int, bool)> count = [&](int v, int p, int f, bool b) {
        int64_t val = cnt[f];
        for (int i = 0; i < M; ++i) {
            val += cnt[f ^ (1 << i)];
        }
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            val += count(u, v, f ^ (1 << (s[u] - 'a')), b);
        }
        if (b) { ans[v] += val; }
        return val;
    };
    function<void(int, int, int, int)> add = [&](int v, int p, int f, int val) {
        cnt[f] += val;
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            add(u, v, f ^ (1 << (s[u] - 'a')), val);
        }
    };
    function<void(int)> solve = [&](int v) {
        dfs(v, -1);
        v = get_centroid(v, -1, length[v]);
        cnt[0] = is_centroid[v] = 1;
        for (int u : adj[v]) {
            if (is_centroid[u]) { continue; }
            ans[v] += count(u, v, (1 << (s[u] - 'a')) ^ (1 << (s[v] - 'a')), 0);
            add(u, v, (1 << (s[u] - 'a')), 1);
        }
        for (int u : adj[v]) {
            if (is_centroid[u]) { continue; }
            add(u, v, (1 << (s[u] - 'a')), -1);
            count(u, v, (1 << (s[u] - 'a')) ^ (1 << (s[v] - 'a')), 1);
            add(u, v, (1 << (s[u] - 'a')), +1);
        }
        for (int u : adj[v]) {
            if (is_centroid[u]) { continue; }
            add(u, v, (1 << (s[u] - 'a')), -1);
        }
        for (int u : adj[v]) {
            if (is_centroid[u]) { continue; }
            solve(u);
        }
    };
    solve(0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
