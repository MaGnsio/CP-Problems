/**
 *    author:  MaGnsi0
 *    created: 21.11.2021 15:41:36
**/
#include <bits/stdc++.h>

using namespace std;

const long long OO = 1e15;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<long long> d(n + 1, OO); 
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    d[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int v = q.top().second, d_v = q.top().first;
        q.pop();
        if (d_v != d[v]) {
            continue;
        }
        for (auto& [u, w] : adj[v]) {
            if (d[v] + 1LL * w < d[u]) {
                d[u] = d[v] + 1LL * w;
                q.push({d[u], u});
            }
        }
    }
    long long sum = 0, maxi = 0;
    for (int i = 0; i < k; ++i) {
        sum += d[a[i]];
        maxi = max(maxi, d[a[i]]);
    }
    cout << 2LL * sum << " " << 2LL * maxi;
}
