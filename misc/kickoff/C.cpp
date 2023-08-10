/**
 *    author:  MaGnsi0
 *    created: 06.05.2023 17:28:13
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    function<bool(int, int)> F = [&](int i, int j) {
        if (a[i][j] == '#') { return false; }
        if (i + 1 >= n || j + 1 >= m) { return false; }
        if (a[i][j + 1] == '#' || a[i + 1][j] == '#' || a[i + 1][j + 1] == '#') { return false; }
        return true;
    };
    union_find dsu(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (F(i, j) == false) { continue; }
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || ni >= n) { continue; }
                if (nj < 0 || nj >= m) { continue; }
                if (F(ni, nj)) {
                    dsu.unite(i * m + j, ni * m + nj);
                }
            }
        }
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (F(i, j)) {
                mp[dsu.find(i * m + j)]++;
            }
        }
    }
    int ans = 0;
    for (auto& [_, x] : mp) {
        ans = max(ans, x);
    }
    cout << ans;
}
