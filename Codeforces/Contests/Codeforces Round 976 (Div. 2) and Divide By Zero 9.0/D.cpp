/**
 *    author:  MaGnsi0
 *    created: 29.09.2024 19:15:49
**/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int M = 11;

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
        vector<vector<vector<int>>> MODs(M, vector<vector<int>>(M));
        for (int mod = 1; mod < M; ++mod) {
            for (int x = 0; x < mod; ++x) {
                int sz = (n / mod) + (n % mod > x);
                MODs[mod][x] = vector<int>(2 * sz + 2);
            }
        }
        for (int i = 0; i < m; ++i) {
            int s; cin >> s;
            int mod; cin >> mod;
            int k; cin >> k;
            if (k == 0) { continue; }
            int e = s + k * mod;
            assert(s % mod == e % mod);
            int l = 2 * (s / mod) + 1;
            int r = 2 * (e / mod);
            MODs[mod][s % mod][l]++;
            MODs[mod][e % mod][r + 1]--;
        }
        for (int mod = 1; mod < M; ++mod) {
            for (int x = 0; x < mod; ++x) {
                int sz = (int)MODs[mod][x].size();
                for (int i = 1; i < sz; ++i) {
                    MODs[mod][x][i] += MODs[mod][x][i - 1];
                }
            }
        }
        union_find dsu(n + 1);
        for (int mod = 1; mod < M; ++mod) {
            for (int x = 0; x < mod; ++x) {
                int sz = (int)MODs[mod][x].size();
                for (int i = 1; i < sz; ++i) {
                    int u = mod * ((i - 1) / 2) + x;
                    int v = mod * (i / 2) + x;
                    if (MODs[mod][x][i] && MODs[mod][x][i - 1]) {
                        dsu.unite(u, v);
                    }
                }
            }
        }
        set<int> parents;
        for (int i = 1; i <= n; ++i) {
            parents.insert(dsu.find(i));
        }
        int ans = (int)parents.size();
        cout << ans << "\n";
    }
}
