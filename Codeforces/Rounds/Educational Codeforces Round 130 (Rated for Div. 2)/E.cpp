/**
 *    author:  MaGnsi0
 *    created: 03.07.2022 21:55:09
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<vector<bool>> a(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        int64_t min_d = INT64_MAX;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            min_d = min(min_d, abs(x[i] - x[j]) + abs(y[i] - y[j]));
        }
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) == min_d) {
                a[i][j] = true;
            }
        }
    }
    function<vector<int>(int)> bfs = [&](int root) {
        vector<int> b;
        vector<bool> visited(n, false);
        queue<int> q;
        b.push_back(root);
        visited[root] = true;
        q.push(root);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u = 0; u < n; ++u) {
                if (!visited[u] && a[v][u]) {
                    b.push_back(u);
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        return b;
    };
    vector<int> c;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (visited[i]) {
            continue;
        }
        vector<int> b = bfs(i);
        bool ok = true;
        for (int j = 0; j < (int)b.size(); ++j) {
            for (int k = j + 1; k < (int)b.size(); ++k) {
                ok &= (a[b[j]][b[k]] && a[b[k]][b[j]]);
            }
        }
        if (!ok) {
            c.push_back(1);
        } else {
            c.push_back((int)b.size());
            for (int j = 0; j < (int)b.size(); ++j) {
                visited[b[j]] = true;
            }
        }
    }
    vector<vector<int64_t>> dp((int)c.size(), vector<int64_t>(n + 1, -1));
    function<int64_t(int, int)> solve = [&](int x, int y) {
        if (x == (int)c.size()) {
            return int64_t(1);
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        dp[x][y] = solve(x + 1, y - 1) * y;
        dp[x][y] %= MOD;
        if (c[x] > 1) {
            int64_t f = 1;
            for (int i = 0; i < c[x]; ++i) {
                f *= int64_t(y - i);
                f %= MOD;
            }
            dp[x][y] += f * solve(x + 1, y - c[x]); 
            dp[x][y] %= MOD;
        }
        return dp[x][y];
    };
    cout << solve(0, n);
}
