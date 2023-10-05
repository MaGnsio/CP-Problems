/**
 *    author:  MaGnsi0
 *    created: 17.02.2023 18:23:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    string s;
    cin >> s;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        adj[p[i]].push_back(i);
    }
    int dfs_time = 0;
    vector<int> in(n), out(n), depth(n);
    function<void(int)> dfs = [&](int v) {
        in[v] = dfs_time++;
        for (auto& u : adj[v]) {
            depth[u] = depth[v] + 1;
            dfs(u);
        }
        out[v] = dfs_time++;
    };
    dfs(0);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        a[depth[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end(), [&](int u, int v) {
                return in[u] < in[v];
            });
    }
    vector<vector<vector<int>>> b(n);
    for (int i = 0; i < n; ++i) {
        b[i].resize((int)a[i].size());
        for (int j = 0; j < (int)a[i].size(); ++j) {
            b[i][j] = vector<int>(26, 0);
            b[i][j][s[a[i][j]] - 'a'] = 1;
        }
        for (int j = 1; j < (int)a[i].size(); ++j) {
            for (int k = 0; k < 26; ++k) {
                b[i][j][k] += b[i][j - 1][k];
            }
        }
    }
    function<bool(int, int)> F = [&](int v, int h) {
        if (h <= depth[v]) {
            return true;
        }
        int L = -1, R = -1;
        int low = 0, high = (int)a[h].size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (in[a[h][mid]] >= in[v]) {
                L = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low = 0, high = (int)a[h].size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (in[a[h][mid]] <= out[v]) {
                R = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (L == -1 || R == -1) {
            return true;
        }
        vector<int> c = b[h][R];
        if (L) {
            for (int i = 0; i < 26; ++i) {
                c[i] -= b[h][L - 1][i];
            }
        }
        int x = 0;
        for (int i = 0; i < 26; ++i) {
            x += (c[i] & 1);
        }
        return x <= 1;
    };
    for (int i = 0; i < m; ++i) {
        int v, h;
        cin >> v >> h;
        cout << (F(v - 1, h - 1) ? "Yes" : "No") << "\n";
    }
}
