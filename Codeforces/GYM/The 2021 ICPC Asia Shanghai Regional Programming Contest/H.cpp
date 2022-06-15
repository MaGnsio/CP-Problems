/**
 *    author:  MaGnsi0
 *    created: 24.05.2022 01:19:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<tuple<int, int, int>> e(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = make_tuple(w, u - 1, v - 1);
    }
    sort(e.begin(), e.end());
    vector<set<pair<int64_t, int>>> query(n);
    for (int i = 0; i < q; ++i) {
        int v, x;
        cin >> v >> x;
        query[v - 1].insert(make_pair(x, i));
    }
    vector<int64_t> ans(q);
    vector<int> parent(n), size(n, 1);
    iota(parent.begin(), parent.end(), 0);
    function<int(int)> find = [&](int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    };
    function<void(tuple<int, int, int>)> unite = [&](tuple<int, int, int> edge) {
        int w = get<0>(edge), u = get<1>(edge), v = get<2>(edge);
        int pu = find(u), pv = find(v);
        if (pu == pv) {
            return;
        }
        if (size[pu] < size[pv]) {
            swap(pu, pv);
        }
        //exclude queries that can't go farther
        while (!query[pu].empty() && query[pu].begin() -> first + a[pu] < w) {
            ans[query[pu].begin() -> second] = query[pu].begin() -> first + a[pu];
            query[pu].erase(query[pu].begin());
        }
        while (!query[pv].empty() && query[pv].begin() -> first + a[pv] < w) {
            ans[query[pv].begin() -> second] = query[pv].begin() -> first + a[pv];
            query[pv].erase(query[pv].begin());
        }
        a[pu] += a[pv];
        parent[pv] = pu;
        size[pu] += size[pv];
        for (auto& x : query[pv]) {
            query[pu].insert(x);
        }
    };
    for (int i = 0; i < m; ++i) {
        unite(e[i]);
    }
    int root = find(0);
    while (!query[root].empty()) {
        ans[query[root].begin() -> second] = query[root].begin() -> first + a[root];
        query[root].erase(query[root].begin());
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
}
