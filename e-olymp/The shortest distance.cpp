/**
 *    author:  MaGnsi0
 *    created: 08/06/2021 21:01:02
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, s;
    cin >> n >> s;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (x) {
                adj[i].push_back(j);
            }
        }
    }
    vector<int> d(n + 1, -1);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (d[u] == -1) {
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << " ";
    }
}
