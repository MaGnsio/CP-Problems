/**
 *    author:  MaGnsi0
 *    created: 21.06.2022 15:25:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<int>> adj(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].emplace_back(v - 1);
        adj[v - 1].emplace_back(u - 1);
        mp[{u - 1, v - 1}] = mp[{v - 1, u - 1}] = i;
    }
    vector<bool> visited_e(n - 1, false), visited_v(n, false);
    set<pair<int, int>> s;
    for (int i = 0; i < k; ++i) {
        s.emplace(0, a[i]);
        visited_v[a[i]] = true;
    }
    while(!s.empty()) {
        int v = s.begin() -> second, d_v = s.begin() -> first;
        s.erase(s.begin());
        if (d_v == d) {
            continue;
        }
        for (auto& u : adj[v]) {
            if (visited_v[u]) {
                continue;
            }
            s.emplace(d_v + 1, u);
            visited_e[mp[{u, v}]] = true;
            visited_v[u] = true;
        }
    }
    int ans = count(visited_e.begin(), visited_e.end(), false);
    cout << ans << "\n";
    for (int i = 0; i < n - 1; ++i) {
        if (!visited_e[i]) {
            cout << i + 1 << " ";
        }
    }
}
