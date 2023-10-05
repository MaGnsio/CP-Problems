/**
 *    author:  MaGnsi0
 *    created: 11.05.2022 15:58:56
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
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            int p;
            cin >> p;
            adj[p - 1].push_back(i);
        }
        string s;
        cin >> s;
        int ans = 0;
        function<int(int, int)> dfs = [&](int v, int p) {
            int cnt = (s[v] == 'B' ? 1 : -1);
            for (auto& u : adj[v]) {
                if (u == p) {
                    continue;
                }
                cnt += dfs(u, v);
            }
            ans += (cnt == 0);
            return cnt;
        };
        dfs(0, -1);
        cout << ans << "\n";
    }
}
