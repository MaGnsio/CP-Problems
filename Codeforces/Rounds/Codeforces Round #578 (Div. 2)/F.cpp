/**
 *    author:  MaGnsi0
 *    created: 18.07.2022 07:32:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m = 2520;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = (a[i] % m + m) % m;
    }
    vector<int> b(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        adj[i].resize(b[i]);
        for (int j = 0; j < b[i]; ++j) {
            cin >> adj[i][j];
            adj[i][j]--;
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    function<void(int, int)> solve = [&](int v, int c) {
        if (dp[v][c] != -1) {
            return;
        }
        int cur_v = v, cur_c = c;
        vector<pair<int, int>> path;
        path.push_back(make_pair(cur_v, cur_c));
        while (!visited[cur_v][cur_c]) {
            visited[cur_v][cur_c] = true;
            cur_c = (cur_c + a[cur_v]) % m;
            cur_v = adj[cur_v][cur_c % b[cur_v]];
            path.push_back(make_pair(cur_v, cur_c));
        }
        if (dp[cur_v][cur_c] != -1) {
            for (auto& [x, y] : path) {
                dp[x][y] = dp[cur_v][cur_c];
            }
        } else {
            int p = (int)path.size();
            set<int> cycle;
            for (int i = p - 2; i >= 0; --i) {
                cycle.insert(path[i].first);
                if (path[i] == path[p - 1]) {
                    break;
                }
                if (i == 0) {
                    cycle.clear();
                }
            }
            int ans = (int)cycle.size();
            for (auto& [x, y] : path) {
                dp[x][y] = ans;
            }
        }
        return;
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            solve(i, j);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int v, c;
        cin >> v >> c;
        cout << dp[v - 1][((c % m) + m) % m] << "\n";
    }
}
