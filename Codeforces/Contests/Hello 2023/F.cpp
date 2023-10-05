/**
 *    author:  MaGnsi0
 *    created: 15.02.2023 15:13:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        adj[p[i]].push_back(i);
    }
    vector<int> size(n, 1);
    for (int i = n - 1; i > 0; --i) {
        size[p[i]] += size[i];
    }
    vector<vector<bool>> dp(n, vector<bool>(32, false));
    for (int v = n - 1; v >= 0; --v) {
        dp[v][a[v]] = true;
        for (auto& u : adj[v]) {
            vector<bool> new_dp(32, false);
            for (int x = 0; x < 32; ++x) {
                if (dp[u][x] == false) { continue; }
                for (int y = 0; y < 32; ++y) {
                    if (dp[v][y] == false) { continue; }
                    new_dp[x ^ y] = true;
                }
            }
            swap(dp[v], new_dp);
        }
        if (size[v] % 2 == 0) {
            dp[v][0] = true;
        }
    }
    if (dp[0][0] == false) {
        cout << -1;
        return 0;
    }
    vector<int> steps;
    function<void(int, int)> build = [&](int v, int x) {
        if (x == 0 && size[v] % 2 == 0) {
            steps.push_back(v + 1);
            steps.push_back(v + 1);
            return;
        }
        int m = (int)adj[v].size();
        vector<vector<bool>> pre_dp(m + 1, vector<bool>(32, false));
        pre_dp[0][a[v]] = true;
        for (int i = 0; i < m; ++i) {
            int u = adj[v][i];
            pre_dp[i + 1] = dp[u];
            vector<bool> new_dp(32, false);
            for (int j = 0; j < 32; ++j) {
                if (pre_dp[i][j] == false) { continue; }
                for (int k = 0; k < 32; ++k) {
                    if (pre_dp[i + 1][k] == false) { continue; }
                    new_dp[j ^ k] = true;
                }
            }
            swap(pre_dp[i + 1], new_dp);
        }
        int cur_x = x;
        for (int i = m - 1; i >= 0; --i) {
            int u = adj[v][i];
            for (int j = 0; j < 32; ++j) {
                if (dp[u][j] == false) { continue; }
                if (pre_dp[i][cur_x ^ j]) {
                    cur_x ^= j;
                    build(u, j);
                    break;
                }
            }
        }
    };
    build(0, 0);
    steps.push_back(1);
    int ans = (int)steps.size();
    cout << ans << "\n";
    for (int step : steps) {
        cout << step << " ";
    }
}
