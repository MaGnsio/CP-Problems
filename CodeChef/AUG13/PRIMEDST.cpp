/**
 *    author:  MaGnsi0
 *    created: 26.06.2023 22:13:52
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 50005;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> primes;
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int64_t ans = 0, all = int64_t(n) * (n - 1) / 2;
    vector<int> size(n), is_centroid(n), cnt(n);
    function<void(int, int)> set_size = [&](int v, int p) {
        size[v] = 1;
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            set_size(u, v);
            size[v] += size[u];
        }
    };
    function<int(int, int, int)> get_centroid = [&](int v, int p, int m) {
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            if (2 * size[u] > m) {
                return get_centroid(u, v, m);
            }
        }
        return v;
    };
    function<void(int, int, int)> dfs = [&](int v, int p, int x) {
        int j = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
        for (int i = j; i < (int)primes.size(); ++i) {
            if (primes[i] - x >= n) { break; }
            ans += cnt[primes[i] - x];
        }
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            dfs(u, v, x + 1);
        }
    };
    function<void(int, int, int, int)> add = [&](int v, int p, int x, int val) {
        cnt[x] += val;
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            add(u, v, x + 1, val);
        }
    };
    function<void(int)> solve = [&](int v) {
        set_size(v, -1);
        v = get_centroid(v, -1, size[v]);
        is_centroid[v] = 1, cnt[0] = 1;
        for (int u : adj[v]) {
            if (is_centroid[u]) { continue; }
            dfs(u, v, 1);
            add(u, v, 1, 1);
        }
        for (int u : adj[v]) {
            if (is_centroid[u]) { continue; }
            add(u, v, 1, -1);
        }
        for (int u : adj[v]) {
            if (is_centroid[u]) { continue; }
            solve(u);
        }
    };
    solve(0);
    cout << fixed << setprecision(6) << 1.0 * ans / all;
}
