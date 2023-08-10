/**
 *    author:  MaGnsi0
 *    created: 14.04.2023 22:27:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    map<int, vector<int>> adj;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }
    int ans = 0;
    map<int, int> b;
    for (int i = 0; i < n; ++i) {
        b[a[i]] = i;
    }
    set<int> done;
    for (int i = 0; i < n; ++i) {
        if (done.count(a[i])) { continue; }
        done.insert(a[i]);
        for (auto& u : adj[a[i]]) {
            if (b.count(u) == 0) { continue; }
            ans = max(ans, b[u] - i + 1);
        }
    }
    cout << ans << "\n";
}
