/**
 *    author:  MaGnsi0
 *    created: 21/06/2021 00:57:22
**/
#include <bits/stdc++.h>
using namespace std;
const double INF = 1e9, EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1), k(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i] >> k[i];
        for (int j = 0; j < n - 1; ++j) {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }
    vector<double> d(n + 1, INF);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    d[1] = 0.0;
    q.push({d[1], 1});
    while (!q.empty()) {
        int v = q.top().second;
        double d_v = q.top().first;
        q.pop();
        if (d[v] < d_v - EPS) {
            continue;
        }
        for (auto& u : adj[v]) {
            if (k[v] == 0) {
                continue;
            }
            double temp = d[v] + sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
            if (d[u] > d[v]) {
                if (temp < d[u] - EPS) {
                    d[u] = temp;
                    q.push({d[u], u});
                }
                k[v]--;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << fixed << setprecision(6) << d[i] << "\n";
    }
}
