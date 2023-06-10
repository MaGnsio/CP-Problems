/**
 *    author:  MaGnsi0
 *    created: 03.06.2023 15:09:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int  n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int X = (x[i] - x[j]);
            int Y = (y[i] - y[j]);
            if (X * X + Y * Y <= d * d) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<bool> infected(n, false);
    function<void(int)> dfs = [&](int v) {
        infected[v] = true;
        for (int u : adj[v]) {
            if (!infected[u]) { dfs(u); }
        }
    };
    dfs(0);
    for (int i = 0; i < n; ++i) {
        cout << (infected[i] ? "Yes" : "No") << "\n";
    }
}
