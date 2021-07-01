/**
 *    author:  MaGnsi0
 *    created: 18/06/2021 02:07:59
**/
#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& parent, int f, int t) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[f] = 0;
    q.push({0, f});
    while (!q.empty()) {
        int v = q.top().second, d_v = q.top().first;
        q.pop();
        if (dist[v] != d_v) {
            continue;
        }
        for (auto& [u, w] : adj[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                q.push({dist[u], u});
                parent[u] = v;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    map<string, int> toInt;
    map<int, string> toStr;
    vector<int> cost(n + 1);
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s >> cost[i];
        toInt[s] = i;
        toStr[i] = s;
    }
    int m;
    cin >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int c;
        string f, t;
        cin >> f >> t >> c;
        adj[toInt[f]].push_back({toInt[t],2 * c + cost[toInt[t]]});
        adj[toInt[t]].push_back({toInt[f],2 * c + cost[toInt[f]]});
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int p;
        string f, t;
        cin >> f >> t >> p;
        vector<int> dist(n + 1, INT_MAX), parent(n + 1, -1);
        dijkstra(adj, dist, parent, toInt[f], toInt[t]);
        double fare = (dist[toInt[t]] + cost[toInt[f]]) * 1.1 / double(p);
        vector<string> path;
        for (int v = toInt[t]; v != -1; v = parent[v]) {
            path.push_back(toStr[v]);
        }
        reverse(path.begin(), path.end());
        cout << "Query #" << i << "\n";
        for (int v = 0; v < path.size(); ++v) {
            if (v) {
                cout << " ";
            }
            cout << path[v];
        }
        cout << "\nEach passenger has to pay : " << fixed << setprecision(2) << fare << " taka\n";
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        if (t > 1) {
            cout << "\n";
        }
        cout << "Map #" << t << "\n";
        cin.ignore();
        solve();
    }
}
