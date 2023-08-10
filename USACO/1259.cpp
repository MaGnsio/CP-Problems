/**
 *    author:  MaGnsi0
 *    created: 08.08.2023 20:17:53
**/
#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent;
    vector<int64_t> length;
    union_find(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int64_t>(n, 1);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    int64_t unite(int x, int y) {
        int Px = find(x);
        int Py = find(y);
        if (Px == Py) {
            return length[Px];
        }
        if (length[Px] < length[Py]) {
            swap(Px, Py);
        }
        parent[Py] = Px;
        length[Px] += length[Py];
        return length[Px];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
        deg[u - 1]++, deg[v - 1]++;
    }
    set<pair<int, int>> S;
    for (int i = 0; i < n; ++i) {
        S.emplace(deg[i], i);
    }
    int lastd = 0;
    vector<bool> gone(n, false);
    vector<int64_t> best_at(n, 0);
    while (!S.empty()) {
        int d = S.begin() -> first;
        vector<int> to_remove;
        while (!S.empty() && S.begin() -> first == d) {
            int v = S.begin() -> second;
            to_remove.push_back(v);
            gone[v] = true;
            best_at[v] = max(lastd, d);
            S.erase(S.begin());
        }
        lastd = max(lastd, d);
        for (int v : to_remove) {
            for (int u : adj[v]) {
                if (gone[u]) { continue; }
                S.erase({deg[u], u});
                S.emplace(--deg[u], u);
            }
        }
    }
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
            return best_at[i] > best_at[j];
        });
    int64_t ans = 0;
    union_find dsu(n);
    gone = vector<bool>(n, false);
    for (int i = 0; i < n; ++i) {
        int v = I[i];
        for (int u : adj[v]) {
            if (!gone[u]) { continue; }
            ans = max(ans, best_at[v] * dsu.unite(u, v));
        }
        gone[v] = true;
    }
    cout << ans;
}
