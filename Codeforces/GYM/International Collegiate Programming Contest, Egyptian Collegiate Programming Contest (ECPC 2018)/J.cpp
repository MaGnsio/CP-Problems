/**
 *    author:  MaGnsi0
 *    created: 24.07.2023 10:18:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("unique.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> out(n / 2);
        vector<vector<int>> adj(n / 2);
        for (int i = 1; i < n; ++i) {
            int u = i / 2;
            int v = ((2 * i) % n) / 2;
            adj[u].push_back(v); out[u]++;
        }
        vector<int> eulerian_path;
        function<void(int)> dfs = [&](int v) {
            while (out[v]) {
                int u = adj[v][--out[v]];
                dfs(u);
            }
            eulerian_path.push_back(v);
        };
        dfs(0);
        reverse(eulerian_path.begin(), eulerian_path.end());
        string ans = "1";
        for (int i = 2; i < n; ++i) {
            int u = eulerian_path[i - 1];
            int v = eulerian_path[i];
            if (4 * u % n == 2 * v % n) {
                ans += "0";
            } else {
                ans += "1";
            }
        }
        ans += "0";
        cout << ans << "\n";
    }
}
