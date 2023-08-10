/**
 *    author:  MaGnsi0
 *    created: 29.06.2023 15:22:05
**/
#include <bits/stdc++.h>
 
using namespace std;
 
struct segment_tree {
    int N;
    int E;
    vector<int> S;
    function<int(int, int)> F;
    segment_tree(int n, int e, function<int(int, int)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, int x) {
        for (S[j += N] += x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    int query(int L, int R) {
        int l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("awesome.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        swap(k1, k2);
        k1 = n - k1 - 1;
        k2 = n - k2 - 1;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        int64_t ans = 0;
        vector<int> length(n, 0);
        vector<bool> is_centroid(n, false);
        segment_tree cnt(n, 0, [](int x, int y) { return x + y; });
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
            if (x > k2) { return; }
            ans += (int64_t)cnt.query(max(0, k1 - x), k2 - x + 1);
            for (int u : adj[v]) {
                if (u == p || is_centroid[u]) { continue; }
                count(u, v, x + 1);
            }
        };
        function<void(int, int, int, int)> add = [&](int v, int p, int x, int val) {
            if (x > k2) { return; }
            cnt.update(x, val);
            for (int u : adj[v]) {
                if (u == p || is_centroid[u]) { continue; }
                add(u, v, x + 1, val);
            }
        };
        function<void(int)> solve = [&](int v) {
            set_length(v, -1);
            v = get_centroid(v, -1, length[v]);
            is_centroid[v] = true;;
            for (int u : adj[v]) {
                if (is_centroid[u]) { continue; }
                count(u, v, 1);
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
        cnt.update(0, 1); solve(0);
        cout << ans << "\n";
    }
}
