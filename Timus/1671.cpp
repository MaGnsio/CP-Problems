/**
 *    author:  MaGnsi0
 *    created: 28/06/2021 18:32:47
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int components;
    vector<int> parent;
    vector<int> length;
    DSU(int N) {
        components = N - 1;
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(N, 1);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) {
            return;
        }
        if (length[a] < length[b]) {
            swap(a, b);
        }
        length[a] += length[b];
        parent[b] = a;
        components--;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    vector<bool> removed(m, false);
    vector<pair<int, int>> edges(m);
    for (auto& [x, y] : edges) {
        cin >> x >> y;
    }
    int q;
    cin >> q;
    vector<int> v(q);
    for (auto& x : v) {
        cin >> x;
        removed[--x] = true;
    }
    reverse(v.begin(), v.end());
    DSU D(n + 1);
    for (int i = 0; i < m; ++i) {
        if (removed[i]) {
            continue;
        }
        D.unite(edges[i].first, edges[i].second);
    }
    vector<int> ans;
    for (auto& x : v) {
        ans.push_back(D.components);
        D.unite(edges[x].first, edges[x].second);
    }
    reverse(ans.begin(), ans.end());
    for (auto& x : ans) {
        cout << x << " ";
    }
}
