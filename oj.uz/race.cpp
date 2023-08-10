/**
 *    author:  MaGnsi0
 *    created: 29.06.2023 15:00:05
**/
#include <bits/stdc++.h>

using namespace std;

int K, ans;
map<int, int> cnt;
const int N = 2e5 + 5;
vector<int> length(N), is_centroid(N);
vector<vector<pair<int, int>>> adj(N);

void dfs(int v, int p) {
    length[v] = 1;
    for (auto [u, _] : adj[v]) {
        if (u == p || is_centroid[u]) { continue; }
        dfs(u, v);
        length[v] += length[u];
    }
}

int get_centroid(int v, int p, int m) {
    for (auto [u, _] : adj[v]) {
        if (u == p || is_centroid[u]) { continue; }
        if (2 * length[u] > m) {
            return get_centroid(u, v, m);
        }
    }
    return v;
}

void count(int v, int p, int j, int x) {
    if (x > K) { return; }
    if (cnt.count(K - x)) {
        ans = min(ans, cnt[K - x] + j);
    }
    for (auto [u, w] : adj[v]) {
        if (u == p || is_centroid[u]) { continue; }
        count(u, v, j + 1, x + w);
    }
}

void add(int v, int p, int j, int x) {
    if (x > K) { return; }
    if (cnt.count(x)) {
        cnt[x] = min(cnt[x], j);
    } else {
        cnt[x] = j;
    }
    for (auto [u, w] : adj[v]) {
        if (u == p || is_centroid[u]) { continue; }
        add(u, v, j + 1, x + w);
    }
}

void solve(int v) {
    dfs(v, -1);
    v = get_centroid(v, -1, length[v]);
    is_centroid[v] = 1;
    cnt.clear(); cnt[0] = 0;
    for (auto [u, w] : adj[v]) {
        if (is_centroid[u]) { continue; }
        count(u, v, 1, w); 
        add(u, v, 1, w);
    }
    for (auto [u, w] : adj[v]) {
        if (is_centroid[u]) { continue; }
        solve(u);
    }
}

int best_path(int n, int k, int H[][2], int L[]) {
    ans = n, K = k;
    for (int i = 0; i < n - 1; ++i) {
        adj[H[i][0]].emplace_back(H[i][1], L[i]);
        adj[H[i][1]].emplace_back(H[i][0], L[i]);
    }
    solve(0);
    return (ans == n ? -1 : ans);
}
