/**
 *    author:  MaGnsi0
 *    created: 30/06/2021 20:08:39
**/
#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    double a = x1 - x2;
    double b = y1 - y2;
    double d = sqrt((a * a) + (b * b));
    return d;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int s, p;
        cin >> s >> p;
        vector<double> x(p), y(p);
        for (int i = 0; i < p; ++i) {
            cin >> x[i] >> y[i];
        }
        vector<vector<double>> adj(p, vector<double>(p, 0.0));
        for (int i = 0; i < p; ++i) {
            for (int j = i + 1; j < p; ++j) {
                adj[i][j] = adj[j][i] = dist(x[i], y[i], x[j], y[j]);
            }
        }
        vector<pair<int, double>> min_edge(p, {-1, 1e9});
        vector<double> w;
        vector<bool> visited(p, false);
        min_edge[0].second = 0.0;
        for (int i = 0; i < p; ++i) {
            int v = -1;
            for (int j = 0; j < p; ++j) {
                if (!visited[j] && (v == -1 || min_edge[j].second < min_edge[v].second)) {
                    v = j;
                }
            }
            visited[v] = true;
            w.push_back(min_edge[v].second);
            for (int j = 0; j < p; ++j) {
                if (adj[v][j] < min_edge[j].second) {
                    min_edge[j] = {v, adj[v][j]};
                }
            }
        }
        sort(w.begin(), w.end());
        cout << fixed << setprecision(2) << w[p - s] << "\n";
    }
}
