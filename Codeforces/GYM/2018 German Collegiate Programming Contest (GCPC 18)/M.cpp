/**
 *    author:  MaGnsi0
 *    created: 24/09/2021 20:17:58
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> v(n, vector<int>(m)), id(n, vector<int>(m));
    vector<pair<int, pair<int, int>>> e(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
            id[i][j] = m * i + j;
            e[id[i][j]] = {v[i][j], {i, j}};
        }
    }
    sort(e.begin(), e.end());
    vector<int> res(q);
    vector<set<int>> adj(n * m);
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        if (x1 == x2 && y1 == y2) {
            res[i] = v[x1][y1];
        } else {
            adj[id[x1][y1]].insert(i);
            adj[id[x2][y2]].insert(i);
        }
    }
    vector<bool> ready(n * m, false);
    vector<int> p(n * m), l(n * m, 1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](int x) {
        int parent = x;
        while (p[parent] != parent) {
            parent = p[parent];
        }
        return p[x] = parent;
    };
    auto connect = [&](set<int>& a, set<int>& b, int v) {
        if ((int)a.size() < (int)b.size()) {
            a.swap(b);
        }
        for (auto& x : b) {
            if (a.find(x) == a.end()) {
                a.insert(x);
            } else {
                a.erase(x);
                res[x] = v;
            }
        }
    };
    auto unite = [&](int x, int y, int v) {
        int a = find(x);
        int b = find(y);
        if (a == b) {
            return;
        }
        if (l[a] < l[b]) { //union by size
            swap(a, b);
        }
        p[b] = a;
        l[a] += b;
        connect(adj[a], adj[b], v);
        return;
    };
    for (int i = 0; i < n * m; ++i) {
        int x = e[i].second.first, y = e[i].second.second, v = e[i].first;
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        for (int j = 0; j < 4; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || nx >= n) {
                continue;
            }
            if (ny < 0 || ny >= m) {
                continue;
            }
            if (!ready[id[nx][ny]]) {
                continue;
            }
            unite(id[x][y], id[nx][ny], v);
        }
        ready[id[x][y]] = true;
    }
    for (int i = 0; i < q; ++i) {
        cout << res[i] << "\n";
    }
}
