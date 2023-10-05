/**
 *    author:  MaGnsi0
 *    created: 19.05.2023 18:06:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        vector<set<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            adj[i].insert(a[i]);
            adj[a[i]].insert(i);
        }
        bool cycle = false;
        vector<bool> visited(n, false);
        function<void(int, int)> dfs = [&](int v, int p) {
            visited[v] = true;
            for (int u : adj[v]) {
                if (visited[u] && u != p) {
                    cycle = true;
                }
                if (!visited[u]) {
                    dfs(u, v);
                }
            }
        };
        int cycles = 0, lines = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == false) {
                cycle = false;
                dfs(i, -1);
                if (cycle) {
                    cycles++;
                } else {
                    lines++;
                }
            }
        }
        cout << cycles + (lines > 0) << " " << cycles + lines << "\n"; 
    }
}
