/**
 *    author:  MaGnsi0
 *    created: 11/07/2021 23:34:08
**/
#include <bits/stdc++.h>
using namespace std;
const int OO = 1e9;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    vector<int> n(4);
    for (int i = 0; i < 4; ++i) {
        cin >> n[i];
    }
    vector<vector<int>> v(4);
    for (int i = 0; i < 4; ++i) {
        v[i].resize(n[i]);
        for (int j = 0; j < n[i]; ++j) {
            cin >> v[i][j];
        }
    }
    vector<int> m(3);
    vector<vector<int>> adj[3];
    for (int i = 0; i < 3; ++i) {
        cin >> m[i];
        adj[i] = vector<vector<int>>(n[i]);
        for (int j = 0; j < m[i]; ++j) {
            int u, v;
            cin >> u >> v;
            adj[i][u - 1].push_back(v - 1);
        }
    }
    //greed from behind.
    for (int i = 2; i >= 0; --i) {
        set<pair<int, int>> s;
        s.insert({OO, -1});
        for (int j = 0; j < n[i + 1]; ++j) {
            s.insert({v[i + 1][j], j});
        }
        for (int j = 0; j < n[i]; ++j) {
            for (auto& x : adj[i][j]) {
                s.erase({v[i + 1][x], x});
            }
            v[i][j] += s.begin() -> first;
            for (auto& x : adj[i][j]) {
                s.insert({v[i + 1][x], x});
            }
        }
    }
    int ans = *min_element(v[0].begin(), v[0].end());
    cout << (ans >= OO ? -1 : ans);
}
