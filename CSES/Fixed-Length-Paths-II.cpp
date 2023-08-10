/**
 *    author:  MaGnsi0
 *    created: 29.06.2023 12:13:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int64_t ans = 0;
    function<int(deque<int>&, int)> prefix = [&](deque<int>& a, int x) {
        if (x < 0) { return 0; }
        if (x + 1 >= (int)a.size()) { return a[0]; }
        return a[0] - a[x + 1];
    };
    function<void(deque<int>&, deque<int>&)> merge = [&](deque<int>& a, deque<int>& b) {
        if ((int)a.size() < (int)b.size()) { swap(a, b); }
        int m = (int)b.size();
        for (int i = 0; i < m - 1; ++i) { b[i] -= b[i + 1]; }
        for (int i = 0; i < m; ++i) {
            ans += int64_t(b[i]) * (prefix(a, k2 - i) - prefix(a, k1 - i - 1));
        }
        for (int i = m - 2; i >= 0; --i) { b[i] += b[i + 1]; }
        for (int i = 0; i < m; ++i) { a[i] += b[i]; }
    };
    function<deque<int>(int, int)> dfs = [&](int v, int p) {
        deque<int> a{1};
        for (int u : adj[v]) {
            if (u == p) { continue; }
            deque<int> b = dfs(u, v);
            b.push_front(b.front());
            merge(a, b);
        }
        return a;
    };
    dfs(0, -1);
    cout << ans;
}
