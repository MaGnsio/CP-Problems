/**
 *    author:  MaGnsi0
 *    created: 02.04.2023 17:25:49
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
    function<vector<int>(int)> bfs = [&](int source) {
        vector<int> d(n, -1);
        queue<int> q;
        d[source] = 0, q.push(source);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto& u : adj[v]) {
                if (d[u] != -1) { continue; }
                d[u] = d[v] + 1; q.push(u);
            }
        }
        return d;
    };
    vector<int> d1 = bfs(0), d2;
    int max_d = *max_element(d1.begin(), d1.end());
    for (int i = 0; i < n; ++i) {
        if (d1[i] == max_d) {
            d1 = bfs(i);
            break;
        }
    }
    max_d = *max_element(d1.begin(), d1.end());
    for (int i = 0; i < n; ++i) {
        if (d1[i] == max_d) {
            d2 = bfs(i);
            break;
        }
    }
    int cur_comp = n;
    vector<int> I(n), ans(n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
            return max(d1[i], d2[i]) > max(d1[j], d2[j]);
        });
    for (int i = n, j = 0; i >= 1; --i) {
        while (j < n && max(d1[I[j]], d2[I[j]]) >= i) {
            cur_comp--, j++;
        }
        ans[i - 1] = min(n, cur_comp + 1);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
