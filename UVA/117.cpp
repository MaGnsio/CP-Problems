/**
 *    author:  MaGnsi0
 *    created: 08/07/2021 19:15:55
**/
#include <bits/stdc++.h>
using namespace std;

int dij(vector<vector<pair<int, int>>>& adj, int a, int b) {
    vector<int> d(26, INT_MAX);
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    d[a] = 0;
    q.push({0, a});
    while (!q.empty()) {
        int v = q.top().second, d_v = q.top().first;
        q.pop();
        if (d_v != d[v]) {
            continue;
        }
        for (auto& [u, w] : adj[v]) {
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                q.push({d[u], u});
            }
        }
    }
    return d[b];
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T = 0;
    while (cin.peek() != EOF) {
        int ans = 0;
        string s;
        vector<int> deg(26, 0);
        vector<vector<pair<int, int>>> adj(26);
        while (cin >> s) {
            if (s == "deadend") {
                break;
            }
            int w = s.size(),  u = s[0] - 'a', v = s[w - 1] - 'a';
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            deg[u]++, deg[v]++;
            ans += w;
        }
        int a = -1, b = -1;
        for (int i = 0; i < 26; ++i) {
            if (deg[i] & 1) {
                if (a == -1) {
                    a = i;
                } else {
                    b = i;
                }
            }
        }
        if (T) {
            cout << "\n";
        }
        cout << ans + (a == -1 ? 0 : dij(adj, a, b));
        T++;
    }
}
