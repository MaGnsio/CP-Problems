/**
 *    author:  MaGnsi0
 *    created: 15.06.2024 20:56:17
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
        vector<vector<char>> a(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j];
            }
        }
        function<int(int, int)> I = [&](int x, int y) {
            return m * (x - 1) + (y - 1);
        };
        function<bool(int, int)> good = [&](int x, int y) {
            if (x <= 0 || x > n) { return false; }
            if (y <= 0 || y > m) { return false; }
            if (a[x][y] == '.') { return false; }
            return true;
        };
        union_find dsu(n * m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
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
        set<int> C;
        map<int, int> SC, LRC, RRC, LCC, RCC;
        vector<int> countR(n + 1, m), countC(m + 1, n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] == '.') { continue; }
                int p = dsu.find(I(i, j));
                C.insert(p);
                SC[p] = dsu.length[p]; 
                LRC[p] = (LRC.count(p) ? min(LRC[p], i) : i);
                RRC[p] = (RRC.count(p) ? max(RRC[p], i) : i);
                LCC[p] = (LCC.count(p) ? min(LCC[p], j) : j);
                RCC[p] = (RCC.count(p) ? max(RCC[p], j) : j);
                countR[i]--, countC[j]--;
            }
        }
        vector<int> compR(n + 2), compC(m + 2);
        vector<vector<int>> compRC(n + 2, vector<int>(m + 2));
        for (int c : C) {
            int x1 = max(LRC[c] - 1, 1);
            int x2 = min(RRC[c] + 1, n);
            int y1 = max(LCC[c] - 1, 1);
            int y2 = min(RCC[c] + 1, m);
            compR[x1] += SC[c];
            compR[x2 + 1] -= SC[c];
            compC[y1] += SC[c];
            compC[y2 + 1] -= SC[c];
            compRC[x1][y1] += SC[c];
            compRC[x1][y2 + 1] -= SC[c];
            compRC[x2 + 1][y1] -= SC[c];
            compRC[x2 + 1][y2 + 1] += SC[c];
        }
        for (int i = 1; i <= n; ++i) {
            compR[i] += compR[i - 1];
        }
        for (int j = 1; j <= m; ++j) {
            compC[j] += compC[j - 1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                compRC[i][j] += compRC[i - 1][j] + compRC[i][j - 1] - compRC[i - 1][j - 1];
            }
        }
        int ans = n + m - 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                ans = max(ans, compR[i] + compC[j] - compRC[i][j] + countR[i] + countC[j] - (a[i][j] == '.'));
            }
        }
        cout << ans << "\n";
    }
}
