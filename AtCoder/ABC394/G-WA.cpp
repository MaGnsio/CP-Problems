/**
 *    author:  MaGnsi0
 *    created: 22.02.2025 15:07:07
**/
#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, length;
    union_find(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(n, 1);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int Px = find(x);
        int Py = find(y);
        if (Px == Py) {
            return;
        }
        if (length[Px] < length[Py]) {
            swap(Px, Py);
        }
        parent[Py] = Px;
        length[Px] += length[Py];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int Q; cin >> Q;
    using query = tuple<int, int, int, int, int, int, int>;
    vector<query> queries(Q);
    for (int q = 0; q < Q; ++q) {
        int i1, j1, f1;
        cin >> i1 >> j1 >> f1; i1--; j1--;
        int i2, j2, f2;
        cin >> i2 >> j2 >> f2; i2--; j2--;
        queries[q] = make_tuple(q, i1, j1, f1, i2, j2, f2);
    }
    sort(queries.begin(), queries.end(), [&](query Q1, query Q2) {
        int x1, y1, x2, y2;
        {
            auto [q1, i1, j1, f1, i2, j2, f2] = Q1;
            x1 = min(a[i1][j1], a[i2][j2]);
            y1 = max(a[i1][j1], a[i2][j2]);
        }
        {
            auto [q2, i1, j1, f1, i2, j2, f2] = Q2;
            x2 = min(a[i1][j1], a[i2][j2]);
            y2 = max(a[i1][j1], a[i2][j2]);
        }
        return make_pair(x1, y1) > make_pair(x2, y2);
    });
    using cell = tuple<int, int, int>;
    vector<cell> cells;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cells.emplace_back(a[i][j], i, j);
        }
    }
    sort(cells.rbegin(), cells.rend());
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, -1, 1, 0};
    int cur_Q = 0, X = -1;
    vector<int> ans(Q);
    union_find dsu(n * m);
    function<int(int, int)> I = [&](int i, int j) {
        return i * m + j;
    };
    function<void()> proccess_queries = [&]() {
        if (cur_Q == Q) { return; }
        auto [q, i1, j1, f1, i2, j2, f2] = queries[cur_Q];
        if (dsu.find(I(i1, j1)) != dsu.find(I(i2, j2))) { return; }
        if (f1 < X || f2 < X) {
            ans[q] = abs(f1 - f2);
        } else {
            ans[q] = f1 + f2 - 2 * X;
        }
        cur_Q++;
        proccess_queries();
    };
    for (auto [x, i, j] : cells) {
        X = x;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || ni >= n) { continue; }
            if (nj < 0 || nj >= m) { continue; }
            if (a[ni][nj] < x) { continue; }
            dsu.unite(I(i, j), I(ni, nj));
            proccess_queries();
        }
    }
    for (int q = 0; q < Q; ++q) {
        cout << ans[q] << "\n";
    }
}
