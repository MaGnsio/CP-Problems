/**
 *    author:  MaGnsi0
 *    created: 01/07/2021 22:19:18
**/
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
    bool operator<(edge e) {
        return (this -> w < e.w);
    }
};

struct DSU {
    int P;
    vector<int> parent;
    vector<bool> special;
    DSU(int N, int P, vector<bool>special) {
        this -> P = P;
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
        this -> special = special;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) {
            return false;
        }
        if (special[a]) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
        P -= (special[a] && special[b]);
        return (P == 1);
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, k, ans;
    cin >> n >> m >> k;
    vector<bool> special(n + 1, false);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        special[x] = true;
    }
    vector<edge> edges(m);
    for (auto& [u, v, w] : edges) {
        cin >> u >> v >> w;
    }
    sort(edges.begin(), edges.end());
    DSU d(n + 1, k, special);
    for (auto& [u, v, w] : edges) {
        if (d.unite(u, v)) {
            ans = w;
            break;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << ans << " ";
    }
}
