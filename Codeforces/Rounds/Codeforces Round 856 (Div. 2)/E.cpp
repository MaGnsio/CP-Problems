/**
 *    author:  MaGnsi0
 *    created: 09.03.2023 00:42:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    const int64_t p = rng() % 1000000000 + 123456, MOD = 1000000000000000009;
    int n;
    cin >> n;
    vector<int64_t> P(n, 1);
    for (int i = 1; i < n; ++i) {
        P[i] = (__int128(p) * P[i - 1]) % MOD;
    }
    int64_t sum = 0;
    vector<int64_t> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
        sum = (sum + P[a[i]]) % MOD;
    }
    set<int64_t> candidates;
    for (int i = 0; i < n; ++i) {
        candidates.insert((sum + P[i]) % MOD);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<int64_t> size(n), hash(n);
    function<void(int, int)> dfs1 = [&](int v, int parent) {
        size[v] = hash[v] = 1;
        for (int u : adj[v]) {
            if (u == parent) { continue; }
            dfs1(u, v);
            size[v] += size[u];
            hash[v] = (hash[v] + (__int128(p) * hash[u]) % MOD) % MOD;
        }
    };
    dfs1(0, -1);
    vector<int> good;
    function<void(int, int)> dfs2 = [&](int v, int parent) {
        if (candidates.count(hash[v])) {
            good.push_back(v + 1);
        }
        for (int u : adj[v]) {
            if (u == parent) { continue; }
            int64_t v_size = size[v], u_size = size[u];
            int64_t v_hash = hash[v], u_hash = hash[u];
            size[v] = v_size - u_size, size[u] = n;
            hash[v] = (v_hash - (__int128(p) * hash[u]) % MOD + MOD) % MOD;
            hash[u] = (u_hash + (__int128(p) * hash[v]) % MOD) % MOD;
            dfs2(u, v);
            size[v] = v_size, size[u] = u_size;
            hash[v] = v_hash, hash[u] = u_hash;
        }
    };
    dfs2(0, -1);
    int ans = (int)good.size();
    cout << ans << "\n";
    sort(good.begin(), good.end());
    for (int i = 0; i < ans; ++i) {
        cout << good[i] << " ";
    }
}
