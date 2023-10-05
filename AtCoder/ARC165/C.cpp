/**
 *    author:  MaGnsi0
 *    created: 17.09.2023 16:36:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> U(m), V(m), W(m);
    for (int i = 0; i < m; ++i) {
        cin >> U[i] >> V[i] >> W[i];
        U[i]--, V[i]--;
    }
    vector<int> color(n, -1);
    vector<vector<int>> adj(n);
    function<bool(int, int)> dfs = [&](int v, int c) {
        color[v] = c;
        for (int u : adj[v]) {
            if (color[u] == color[v]) {
                return false;
            }
            if (color[u] == -1 && !dfs(u, c ^ 1)) {
                return false;
            }
        }
        return true;
    };
    function<int64_t(int64_t)> F = [&](int64_t x) {
        color = vector<int>(n, -1);
        adj = vector<vector<int>>(n);
        vector<vector<int64_t>> Ws(n);
        for (int i = 0; i < m; ++i) {
            if (W[i] < x) {
                adj[U[i]].push_back(V[i]);
                adj[V[i]].push_back(U[i]);
                Ws[U[i]].push_back(W[i]);
                Ws[V[i]].push_back(W[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            sort(Ws[i].begin(), Ws[i].end());
            if ((int)Ws[i].size() >= 2 && Ws[i][0] + Ws[i][1] < x) {
                return false;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1 && dfs(i, 0) == false) {
                return false;
            }
        }
        return true;
    };
    int64_t low = 1, high = 1e15, ans = 1;
    while (low <= high) {
        int64_t mid = low + (high - low) / 2;
        if (F(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans;
}
