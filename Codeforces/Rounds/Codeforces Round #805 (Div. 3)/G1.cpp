/**
 *    author:  MaGnsi0
 *    created: 10.07.2022 16:32:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        set<int> s;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            s.insert(v - 1);
        }
        bool ok = true;
        function<bool(int, int)> dfs = [&](int v, int p) {
            int cnt = 0;
            for (auto& u : adj[v]) {
                if (u != p) {
                    cnt += dfs(u, v);
                }
            }
            ok &= ((cnt < 2) || (cnt == 2 && v == *s.begin()));
            return (cnt + s.count(v)); 
        };
        dfs(*s.begin(), -1);
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
