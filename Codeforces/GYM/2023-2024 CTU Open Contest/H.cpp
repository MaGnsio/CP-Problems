/**
 *    author:  MaGnsi0
 *    created: 26.01.2024 15:40:37
**/
#include <bits/stdc++.h>

using namespace std;

int SQ = 320;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int Q; cin >> Q;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; a[i] += x;
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; a[i] -= x;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        b[u]++, b[v]++;
    }
    for (int i = 0; i < n; ++i) {
        sort(adj[i].begin(), adj[i].end(), [&](int x, int y) {
                return b[x] > b[y];
            });
    }
    for (int i = 0; i < n; ++i) {
        c[i] += a[i];
        for (int j : adj[i]) {
            if (b[j] > SQ) { continue; }
            c[i] += a[j];
        }
    }
    while (Q--) {
        string command; cin >> command;
        if (command == "add") {
            int add; cin >> add;
            string t; cin >> t;
            int i; cin >> i; i--;
            a[i] += (t == "desk" ? 1 : -1) * add;
            c[i] += (t == "desk" ? 1 : -1) * add;
            if (b[i] <= SQ) {
                for (int j : adj[i]) {
                    c[j] += (t == "desk" ? 1 : -1) * add;
                }
            }
        } else {
            int i; cin >> i; i--;
            int ans = c[i];
            for (int j : adj[i]) {
                if (b[j] <= SQ) { break; }
                ans += a[j];
            }
            cout << (ans > 0 ? "desks" : (ans < 0 ? "monitors" : "same")) << "\n";
        }
    }
}
