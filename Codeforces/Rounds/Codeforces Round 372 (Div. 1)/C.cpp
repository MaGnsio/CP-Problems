/**
 *    author:  MaGnsi0
 *    created: 30.06.2023 23:42:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m;
    cin >> n >> m;
    vector<vector<pair<int, int64_t>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    if (m == 1) {
        cout << int64_t(n) * (n - 1);
        return 0;
    }
    function<int64_t(int64_t)> phi = [&](int64_t x) {
        int64_t result = x;
        for (int64_t i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                while (x % i == 0) { x /= i; }
                result -= result / i;
            }
        }
        if (x > 1) { result -= result / x; }
        return result;
    };
    int64_t P = phi(m);
    function<int64_t(int64_t, int64_t)> power = [&](int64_t b, int64_t p) {
        int64_t res = 1;
        while (p) {
            if (p & 1) { res = res * b % m; }
            b = b * b % m;
            p /= 2;
        }
        return res;
    };
    int64_t ans = 0;
    map<int, int64_t> cnt;
    vector<int64_t> length(n), is_centroid(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        length[v] = 1;
        for (auto [u, _] : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            dfs(u, v);
            length[v] += length[u];
        }
    };
    function<int(int, int, int)> get_centroid = [&](int v, int p, int k) {
        for (auto [u, _] : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            if (2 * length[u] > k) {
                return get_centroid(u, v, k);
            }
        }
        return v;
    };
    function<void(int, int, int64_t, int64_t, int)> add = [&](int v, int p, int64_t p10, int64_t mod, int val) {
        cnt[mod] += val;
        for (auto [u, w] : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            add(u, v, (10 * p10) % m, (mod + 10 * p10 * w) % m, val);
        }
    };
    function<void(int, int, int64_t, int64_t)> count = [&](int v, int p, int64_t p10, int64_t mod) {
        int64_t x = (m - mod) % m;
        x *= power((10LL * p10) % m, P - 1);
        x %= m;
        ans += cnt[x];
        for (auto [u, w] : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            count(u, v, (10LL * p10) % m, int64_t(10LL * mod + w) % m);
        }
    };
    function<void(int)> solve = [&](int v) {
        dfs(v, -1); cnt.clear();
        v = get_centroid(v, -1, length[v]);
        is_centroid[v] = cnt[0] = 1;
        for (auto [u, w] : adj[v]) {
            if (is_centroid[u]) { continue; }
            add(u, v, 1, w % m, 1);
        }
        for (auto [u, w] : adj[v]) {
            if (is_centroid[u]) { continue; }
            add(u, v, 1, w % m, -1);
            count(u, v, 1, w % m);
            add(u, v, 1, w % m, +1);
        }
        ans += cnt[0] - 1;
        for (auto [u, _] : adj[v]) {
            if (is_centroid[u]) { continue; }
            solve(u);
        }
    };
    solve(0);
    cout << ans;
}
