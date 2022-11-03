#include <bits/stdc++.h>
using namespace std;

const int N = 51;
char a[N][N];
int n, m;

unordered_map<char, vector<pair<int, int>>> mp;
pair<int, int> nxt[N][N][4];
const int M = 1e4 + 10;
int d[N][N][M];

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

bool valid(int r, int c) {
    return (r >= 0 && c >= 0 && r < n && c < m);
}

pair<int,int> solve(int i, int j, int k) {
    if (nxt[i][j][k].first != -2) { return nxt[i][j][k]; }
    int ni= i + dx[k];
    int nj= j + dy[k];
    if (valid(ni, nj) && a[ni][nj] == a[i][j]) {
        return nxt[i][j][k] = solve(ni, nj, k);
    }
    return nxt[i][j][k] = {ni, nj};
}
int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            mp[a[i][j]].push_back({i, j});
            for (int k = 0; k < 4; k++) {
                nxt[i][j][k]= {-2, -2};
            }
        }
    }
    string s;
    cin >> s;
    s += '*';
    queue<vector<int>> q;
    q.push({0, 0, 0});
    d[0][0][0]= 0;
    memset(d, -1, sizeof d);
    while (q.size()) {
        auto v = q.front();
        q.pop();
        int ii = v[0], jj = v[1], p = v[2];
        if (p == s.length()) {
            cout << d[ii][jj][p] << "\n";
            return 0;
        }
        for (int k = 0; k < 4; ++k) {
            int ni = solve(ii, jj, k).first;
            int nj = solve(ii, jj, k).second;
            if (valid(ni, nj) && d[ni][nj][p] == -1) {
                d[ni][nj][p]= 1 + d[ii][jj][p];
                q.push({ni, nj, p});
            }
        }
        if (a[ii][jj] == s[p] && d[ii][jj][p + 1] == -1) {
            d[ii][jj][p + 1]= 1 + d[ii][jj][p];
            q.push({ii, jj, p + 1});
        }
    }
}
