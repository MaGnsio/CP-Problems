/**
 *    author:  MaGnsi0
 *    created: 23.12.2023 15:02:55
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> b(n, vector<int>(m, -1));
    vector<vector<int>> c(n, vector<int>(m, -1));
    int greens = 0, reds = 0, M = 0;
    function<void(int, int)> dfs = [&](int x, int y) {
        b[x][y] = greens;
        c[x][y] = M++;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n) { continue; }
            if (ny < 0 || ny >= m) { continue; }
            if (a[nx][ny] == '.') { continue; }
            if (b[nx][ny] != -1) { continue; }
            dfs(nx, ny);
        }
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            reds += a[i][j] == '.';
            if (a[i][j] == '#' && b[i][j] == -1) {
                dfs(i, j);
                greens++;
            }
        }
    }
    int E = 0;
    vector<vector<pair<int, int>>> adj(M);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (a[x][y] == '.') { continue; }
            for (int i = 2; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n) { continue; }
                if (ny < 0 || ny >= m) { continue; }
                if (a[nx][ny] == '.') { continue; }
                adj[c[x][y]].emplace_back(c[nx][ny], E);
                adj[c[nx][ny]].emplace_back(c[x][y], E);
                E++;
            }
        }
    }
    vector<set<int>> bcc;
    vector<int> minh(M), h(M);
    vector<bool> visited(M), collected(E);
    function<void(int, int)> collect = [&](int v, int p) {
        for (auto [u, e] : adj[v]) {
            if (!collected[e]) {
                bcc.back().insert(u);
                bcc.back().insert(v);
                collected[e] = true;
                if (u != p) {
                    collect(u, p);
                }
            }
        }
    };
    function<void(int)> dfs_ = [&](int v) {
        visited[v] = true;
        minh[v] = h[v];
        for (auto [u, e] : adj[v]) {
            if (!visited[u]) {
                h[u] = h[v] + 1;
                dfs_(u);
                minh[v] = min(minh[v], minh[u]);
                if (minh[u] == h[v] && !collected[e]) {
                    bcc.emplace_back();
                    collect(u, v);
                }
            } else {
                minh[v] = min(minh[v], h[u]);
            }
        }
    };
    for (int i = 0; i < M; ++i) {
        if (!visited[i]) {
            if (adj[i].empty()) {
                bcc.push_back({i});
            } else {
                dfs_(i);
            }
        }
    }
    vector<int> counts(M, 0);
    for (set<int> s : bcc) {
        for (int v : s) {
            counts[v]++;
        }
    }
    int64_t ans = 0, p = power(M, MOD - 2);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (a[x][y] == '.') { continue; }
            int cc = counts[c[x][y]];
            int new_greens = greens + (cc == 1 ? (adj[c[x][y]].empty() ? -1 : 0) : cc - 1);
            ans += p * new_greens % MOD;
            ans %= MOD;
        }
    }
    cout << ans;
}
