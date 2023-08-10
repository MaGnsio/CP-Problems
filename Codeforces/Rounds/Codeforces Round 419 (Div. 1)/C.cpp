/**
 *    author:  MaGnsi0
 *    created: 18.07.2023 23:49:34
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 5005, OO = 1e13;

vector<int> adj[N];
int64_t a[N], b[N], size_[N], dp[N][N][2];

void dfs(int v) {
    dp[v][0][0] = 0;
    dp[v][1][0] = a[v]; 
    dp[v][1][1] = a[v] - b[v];
    for (int u : adj[v]) {
        dfs(u);
        for (int i = size_[v]; i >= 0; --i) {
            for (int j = size_[u]; j >= 0; --j) {
                dp[v][i + j][0] = min(dp[v][i + j][0], dp[v][i][0] + dp[u][j][0]);
                dp[v][i + j][1] = min(dp[v][i + j][1], dp[v][i][1] + dp[u][j][0]);
                dp[v][i + j][1] = min(dp[v][i + j][1], dp[v][i][1] + dp[u][j][1]);
            }
        }
        size_[v] += size_[u];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, have;
    cin >> n >> have;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        if (i > 1) {
            int u; cin >> u;
            adj[u].push_back(i);
        }
    }
    for (int i = 0; i <= n; ++i) {
        size_[i] = 1;
        for (int j = 0; j <= n; ++j) {
            dp[i][j][0] = dp[i][j][1] = OO;
        }
    }
    dfs(1);
    for (int i = n; i >= 0; --i) {
        if (dp[1][i][0] <= have || dp[1][i][1] <= have) {
            cout << i;
            return 0;
        }
    }
}
