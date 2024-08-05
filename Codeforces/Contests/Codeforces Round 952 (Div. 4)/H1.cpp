/**
 *    author:  MaGnsi0
 *    created: 15.06.2024 19:00:48
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        function<int(int, int)> I = [&](int x, int y) {
            return m * x + y;
        };
        function<bool(int, int)> good = [&](int x, int y) {
            if (x < 0 || x >= n) { return false; }
            if (y < 0 || y >= m) { return false; }
            if (a[x][y] == '.') { return false; }
            return true;
        };
        union_find dsu(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '.') { continue; }
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (good(ni, nj)) {
                        dsu.unite(I(i, j), I(ni, nj));
                    }
                }
            }
        }
        vector<int> R(n, m), C(m, n);
        vector<set<int>> compR(n);
        vector<set<int>> compC(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (good(i, j)) {
                    compR[i].insert(dsu.find(I(i, j)));
                    compC[j].insert(dsu.find(I(i, j)));
                    R[i]--, C[j]--;
                }
                if (good(i - 1, j)) {
                    compR[i].insert(dsu.find(I(i - 1, j)));
                }
                if (good(i + 1, j)) {
                    compR[i].insert(dsu.find(I(i + 1, j)));
                }
                if (good(i, j - 1)) {
                    compC[j].insert(dsu.find(I(i, j - 1)));
                }
                if (good(i, j + 1)) {
                    compC[j].insert(dsu.find(I(i, j + 1)));
                }
            }
        }
        int ans = max(n, m);
        for (int i = 0; i < n; ++i) {
            int val = R[i];
            for (int c : compR[i]) {
                val += dsu.length[c];
            }
            ans = max(ans, val);
        }
        for (int i = 0; i < m; ++i) {
            int val = C[i];
            for (int c : compC[i]) {
                val += dsu.length[c];
            }
            ans = max(ans, val);
        }
        cout << ans << "\n";
    }
}
