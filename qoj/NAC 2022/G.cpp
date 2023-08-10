#include <bits/stdc++.h>

using namespace std;

const int N = 504;

int n, m;

char a[N][N];

int vis[N * N + 3];

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int x[N * N + 3], y[N * N + 3], adj[N * N + 10], ind[N][N];

vector<int> ad[N * N + 10];

void add_cycle(int root) {
    int cur = adj[root];
    while (cur != root) {
        ind[x[cur]][y[cur]] = root;
        cur = adj[cur];
    }
}

void dfs1(int node) {
    vis[node] = 1;
    int nxt = adj[node];
    if (!vis[nxt]) {
        dfs1(nxt);
    } else if (vis[nxt] == 1) {
        add_cycle(nxt);
    }
    vis[node] = 2;
}

bool taken[N][N];
vector<pair<int, int>> gr[N * N + 3], by_me[N * N];
vector<int> is_r(N * N + 4, 1);

int dfs(int i, int p = -1) {
    int sc = 0;
    for (auto ch: gr[i]) {
        if (!taken[ch.first][ch.second]) {
            sc++;
            taken[ch.first][ch.second] = 1;
            by_me[i].push_back(ch);
        }
    }
    int te = 0;
    for (int ch: ad[i]) {
        if (ch == p) continue;
        te = max(te, dfs(ch, i));
    }
    sc += te;
    for (auto ch: by_me[i]) {
        taken[ch.first][ch.second] = 0;
    }
    return sc;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = '.';
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    memset(ind, -1, sizeof ind);
    memset(adj, -1, sizeof -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != '.' && a[i][j] != '#') {
                ind[i][j] = i * (m - 1) + j;
                x[i * (m - 1) + j] = i;
                y[i * (m - 1) + j] = j;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '>' && ~ind[i][j + 1]) {
                adj[ind[i][j]] = ind[i][j + 1];
            } else if (a[i][j] == 'v' && ~ind[i + 1][j]) {
                adj[ind[i][j]] = ind[i + 1][j];
            } else if (a[i][j] == '<' && ~ind[i][j - 1]) {
                adj[ind[i][j]] = ind[i][j - 1];
            } else if (a[i][j] == '^' && ~ind[i - 1][j]) {
                adj[ind[i][j]] = ind[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j += 1) {
            if (~ind[i][j] && vis[i * (m - 1) + j] == 0) {
                dfs1(i * (m - 1) + j);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '>' && ~ind[i][j + 1] && ind[i][j + 1] != ind[i][j]) {
                ad[ind[i][j + 1]].push_back(ind[i][j]);
            } else if (a[i][j] == 'v' && ~ind[i + 1][j] && ind[i + 1][j] != ind[i][j]) {
                ad[ind[i + 1][j]].push_back(ind[i][j]);
            } else if (a[i][j] == '<' && ~ind[i][j - 1] && ind[i][j - 1] != ind[i][j]) {
                ad[ind[i][j - 1]].push_back(ind[i][j]);
            } else if (a[i][j] == '^' && ~ind[i - 1][j] && ind[i - 1][j] != ind[i][j]) {
                ad[ind[i - 1][j]].push_back(ind[i][j]);
            }
            is_r[ind[i][j]] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#') {
                for (int k = 0; k < 4; ++k) {
                    if (~ind[i + dx[k]][j + dy[k]]) {
                        gr[ind[i + dx[k]][j + dy[k]]].push_back({i, j});
                    };
                }
            }
        }
    }
    for (int i = 0; i <= N * N; i++) {
        sort(gr[i].begin(), gr[i].end()), gr[i].erase(unique(gr[i].begin(), gr[i].end()), gr[i].end());
    }
    int ans = 0;
    for (int i = 0; i < N * N + 2; i++) {
        if (is_r[i]) {
            ans = max(ans, dfs(i));
        }
    }
    return 0;
}
