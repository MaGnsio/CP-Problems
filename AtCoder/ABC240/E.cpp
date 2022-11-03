/**
 *    author:  MaGnsi0
 *    created: 23.02.2022 01:32:49
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
    int k = 1;
    vector<int> L(n), R(n);
    function<pair<int, int>(int, int)> solve = [&](int v, int p) {
        int l = INT_MAX, r = INT_MIN;
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            pair<int, int> x = solve(u, v);
            l = min(l, x.first), r = max(r, x.second);
        }
        if (l == INT_MAX) {
            l = r = k++;
        }
        L[v] = l, R[v] = r;
        return make_pair(l, r);
    };
    solve(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << L[i] << " " << R[i] << "\n";
    }
}
