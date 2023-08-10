/**
 *    author:  MaGnsi0
 *    created: 07.07.2023 20:38:38
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 4e4;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) { a[i].push_back(j); }
            while (x % j == 0) { x /= j; }
        }
        if (x > 1) { a[i].push_back(x); }
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = (int)a[i].size();
    }
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].emplace_back(v - 1, i);
        adj[v - 1].emplace_back(u - 1, i);
    }
    vector<int64_t> ans(n - 1);
    function<int(int, int)> count_all = [&](int v, int p) {
        int x = 1;
        for (auto [u, j] : adj[v]) {
            if (u == p) { continue; }
            int y = count_all(u, v);
            ans[j] = 1LL * y * (n - y);
            x += y;
        }
        return x;
    };
    vector<int> length(n), is_centroid(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        length[v] = 1;
        for (auto [u, _] : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            dfs(u, v); length[v] += length[u];
        }
    };
    function<int(int, int, int)> get_centroid = [&](int v, int p, int m) {
        for (auto [u, _] : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            if (2 * length[u] > m) { return get_centroid(u, v, m); }
        }
        return v;
    };
    vector<int64_t> cnt(N, 0);
    function<void(int, int, int)> add = [&](int v, int p, int val) {
        for (int mask = 1; mask < (1 << b[v]); ++mask) {
            int x = 1;
            for (int i = 0; i < b[v]; ++i) {
                if ((mask >> i) & 1) { x *= a[v][i]; }
            }
            cnt[x] += val;
        }
        for (auto [u, j] : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            add(u, v, val);
        }
    };
    function<int64_t(int, int)> count = [&](int v, int p) {
        int64_t res = 0;
        for (int mask = 1; mask < (1 << b[v]); ++mask) {
            int x = 1;
            for (int i = 0; i < b[v]; ++i) {
                if ((mask >> i) & 1) { x *= a[v][i]; }
            }
            if (__builtin_popcount(mask) & 1) {
                res += cnt[x];
            } else {
                res -= cnt[x];
            }
        }
        for (auto [u, j] : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            int64_t val = count(u, v);
            ans[j] -= val, res += val;
        }
        return res;
    };
    function<void(int)> solve = [&](int v) {
        dfs(v, -1);
        v = get_centroid(v, -1, length[v]);
        is_centroid[v] = 1;
        add(v, -1, +1);
        for (auto [u, j] : adj[v]) {
            if (is_centroid[u]) { continue; }
            add(u, v, -1);
            ans[j] -= count(u, v);
            add(u, v, +1);
        }
        add(v, -1, -1);
        for (auto [u, _] : adj[v]) {
            if (is_centroid[u]) { continue; }
            solve(u);
        }
    };
    count_all(0, -1), solve(0);
    for (int i = 0; i < n - 1; ++i) {
        cout << ans[i] << " ";
    }
}
