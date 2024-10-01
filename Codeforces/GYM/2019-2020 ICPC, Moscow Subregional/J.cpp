/**
 *    author:  MaGnsi0
 *    created: 01.10.2024 19:45:54
**/
#include <bits/stdc++.h>

using namespace std;

int64_t F(int64_t n) {
    return n * (n + 1) / 2;
}

struct vertex {
    int64_t n, good;
    set<pair<int, int>> intervals;
    vertex(int64_t N) {
        n = N;
        good = F(N);
        intervals.emplace(-1, -1);
        intervals.emplace(n, n);
    }
    void add_interval(int l, int r) {
        auto nxt_ = intervals.upper_bound({r, r});
        auto prv_ = prev(nxt_);
        int l1 = prv_ -> first;
        int r1 = prv_ -> second;
        int l2 = prv_ -> first;
        int r2 = prv_ -> second;
        good -= F((l2 + 1) - (r1 - 1) + 1);
        if (r1 == l + 1 && l2 == r - 1) {
            good += F(r - l + 1); 
        } else if (r1 == l + 1) {
            good += F(r - l1 + 1);
            good += F((l2 - 1) - (r + 1) + 1);
        } else if (l2 == r - 1) {
            good += F((r1 + 1) - (l - 1) + 1);
            good += F(r2 - l + 1);
        } else {
            good += F((r1 + 1) - (l - 1) + 1);
            good += F(r - l + 1);
            good += F((l2 - 1) - (r + 1) + 1);
        }
        intervals.emplace(l, r);
    }
    int64_t get_node_contribution() {
        return F(n) - good;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; ++v) {
        int u; cin >> u; u--;
        adj[u].push_back(v);
    }
    int64_t ans = 0;
    vector<vertex> a(n, vertex(n));
    function<void(int)> dfs = [&](int v) {
        int big = -1;
        for (int u : adj[v]) {
            dfs(u);
            if (big == -1 || a[u].intervals.size() > a[big].intervals.size()) {
                big = u;
            }
        }
        if (big != -1) {
            swap(a[v], a[big]);
        }
        cout << v + 1 << "<====\n";
        for (int u : adj[v]) {
            if (u == big) { continue; }
            for (auto [l, r] : a[u].intervals) {
                a[v].add_interval(l, r);
            }
        }
        a[v].add_interval(v, v);
        cout << a[v].good << "\n";
        for (auto [l, r] : a[v].intervals) {
            cout << l + 1 << " " << r + 1 << "\n";
        }
        ans += a[v].get_node_contribution();
    };
    dfs(0);
    cout << ans << "\n";
}
