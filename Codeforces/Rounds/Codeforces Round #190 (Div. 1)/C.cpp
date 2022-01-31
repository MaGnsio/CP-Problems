/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 17:29:55
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
    vector<int> size(n, 0);
    vector<char> res(n);
    vector<bool> used(n, false);
    function<int(int, int)> set_sizes = [&](int v, int p) {
        size[v] = 1;
        for (auto& u : adj[v]) {
            if (!used[u] && u != p) {
                size[v] += set_sizes(u, v);
            }
        }
        return size[v];
    };
    function<int(int)> centroid = [&](int v) {
        set_sizes(v, -1);
        int m = size[v] / 2, p = -1;
        while (true) {
            bool good = true;
            for (auto& u : adj[v]) {
                if (!used[u] && u != p && m < size[u]) {
                    p = v, v = u;
                    good = false;
                    break;
                }
            }
            if (good) {
                break;
            }
        }
        return v;
    };
    function<void(int, char)> solve = [&](int v, char c) {
        v = centroid(v);
        res[v] = c;
        used[v] = true;
        for (auto& u : adj[v]) {
            if (!used[u]) {
                solve(u, char(c + 1));
            }
        }
    };
    solve(0, 'A');
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
}
