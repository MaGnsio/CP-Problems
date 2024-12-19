/**
 *    author:  MaGnsi0
 *    created: 19.12.2024 22:55:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k; k++;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> s(n);
        function<void(int, int)> get_s = [&](int v, int p) {
            s[v] = 1;
            for (int u : adj[v]) {
                if (u == p) { continue; }
                get_s(u, v);
                s[v] += s[u];
            }
        };
        get_s(0, -1);
        function<pair<int, int>(int, int, int)> dfs = [&](int v, int p, int x) {
            if (s[v] == x) {
                return make_pair(1, 0);
            }
            if (s[v] < x) {
                return make_pair(0, s[v]);
            }
            pair<int, int> res = {0, 0};
            for (int u : adj[v]) {
                if (u == p) { continue; }
                auto add = dfs(u, v, x);
                res.first += add.first;
                res.second += add.second;
            }
            if (res.second + 1 >= x) {
                res.first++;
                res.second = 0;
            } else {
                res.second++;
            }
            return res;
        };
        function<bool(int)> F = [&](int x) {
            return dfs(0, -1, x).first >= k;
        };
        int low = 1, high = n, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid; low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
