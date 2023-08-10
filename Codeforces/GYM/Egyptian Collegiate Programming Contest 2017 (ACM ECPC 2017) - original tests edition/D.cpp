/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 14:42:01
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 1e5 + 5;

int a[N], c[M], parent[N], length[N];
vector<int> b[M], d[M];

struct union_find {
    union_find(int n) {
        iota(parent, parent + n, 0);
        for (int i = 0; i < n; ++i) {
            length[i] = 1;
        }
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
        if (Px == Py) { return; }
        if (length[Px] < length[Py]) {
            swap(Px, Py);
        }
        parent[Py] = Px;
        length[Px] += length[Py];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("dream.in", "r", stdin);
    for (int i = 1; i < M; ++i) {
        for (int j = i; j < M; j += i) {
            d[j].push_back(i);
        }
    }
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int x : d[a[i]]) {
                c[x]++;
                b[x].push_back(i);
            }
        }
        int m = *max_element(a, a + n);
        int64_t ans = 0, edges = 0;
        union_find dsu(n);
        for (int g = m; g; --g) {
            if (c[g] < 2) { continue; }
            for (int j : b[g]) {
                if (dsu.find(b[g][0]) == dsu.find(j)) { continue; }
                dsu.unite(b[g][0], j);
                ans += g;
                edges++;
            }
            if (edges == n - 1) { break; }
        }
        for (int i = 0; i < n; ++i) {
            for (int x : d[a[i]]) {
                c[x]--;
                b[x].pop_back();
            }
        }
        cout << "Case " << t << ": " << ans << "\n";
    }
}
