/**
 *    author:  MaGnsi0
 *    created: 26.06.2023 19:27:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int64_t ans = 0;
    vector<int> length(n, 0), cnt(n, 0);
    vector<bool> is_centroid(n, false);
    function<void(int, int)> set_length = [&](int v, int p) {
        length[v] = 1;
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            set_length(u, v);
            length[v] += length[u];
        }
    };
    function<int(int, int, int)> get_centroid = [&](int v, int p, int m) {
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            if (2 * length[u] > m) {
                return get_centroid(u, v, m);
            }
        }
        return v;
    };
    function<void(int, int, int)> count = [&](int v, int p, int x) {
        if (x > k) { return; }
        ans += cnt[k - x];
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            count(u, v, x + 1);
        }
    };
    function<void(int, int, int, int)> add = [&](int v, int p, int x, int val) {
        cnt[x] += val;
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            add(u, v, x + 1, val);
        }
    };
    function<void(int, int)> solve = [&](int v, int p) {
        set_length(v, p);
        if (length[v] <= k) { return; }
        int centriod = get_centroid(v, p, length[v]);
        is_centroid[centriod] = true; cnt[0] = 1;
        for (int u : adj[centriod]) {
            if (is_centroid[u]) { continue; }
            count(u, centriod, 1);
            add(u, centriod, 1, 1);
        }
        for (int u : adj[centriod]) {
            if (is_centroid[u]) { continue; }
            add(u, centriod, 1, -1);
        }
        for (int u : adj[centriod]) {
            if (is_centroid[u]) { continue; }
            solve(u, centriod);
        }
    };
    solve(0, -1);
    cout << ans;
}
