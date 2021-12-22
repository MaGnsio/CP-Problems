/**
 *    author:  MaGnsi0
 *    created: 23.10.2021 20:05:24
**/
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int OO = 2e15;

struct edge{
    int v, w, c;
};

bool good(int& n, int& m, int& k, int& t, vector<vector<edge>>& adj) {
    vector<int> d(5 * n, OO);
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
        int cur_c = (v / n);
        for (auto& [u, w, c] : adj[v]) {
            if (d[v] + w + (c != cur_c) * t < d[u]) {
                d[u] = d[v] + w + (c != cur_c) * t;
                q.push({d[u], u});
            }
        }
    }
    int mini = OO;
    for (int i = 0; i < 5; ++i) {
        mini = min(mini, d[(n - 1) + (i * n)]);
    }
    return (mini <= k);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<edge>> adj(5 * n);
        vector<vector<pair<int, int>>> adj0(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            char ch;
            cin >> u >> v >> w >> ch;
            u--, v--;
            int c = (ch - 'a');
            for (int j = 0; j < 5; ++j) {
                adj[u + (j * n)].push_back({v + (c * n), w, c});
                adj[v + (j * n)].push_back({u + (c * n), w, c});
            }
            if (ch == 'a') {
                adj0[u].push_back({v, w});
                adj0[v].push_back({u, w});
            }
        }
        vector<int> d(n, OO);
        {
            using pii = pair<int, int>;
            priority_queue<pii, vector<pii>, greater<pii>> q;
            d[0] = 0;
            q.push({0, 0});
            while (!q.empty()) {
                int v = q.top().second, d_v = q.top().first;
                q.pop();
                if (d[v] != d_v) {
                    continue;
                }
                for (auto& [u, w] : adj0[v]) {
                    if (d[v] + w < d[u]) {
                        d[u] = d[v] + w;
                        q.push({d[u], u});
                    }
                }
            }
            if (d[n - 1] <= k) {
                cout << "relaxing\n";
                continue;
            }
        }
        int l = 1, r = 1e9, res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (good(n, m, k, mid, adj)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (res == -1) {
            cout << "impossible\n";
        } else {
            cout << res << "\n";
        }
    }
}
