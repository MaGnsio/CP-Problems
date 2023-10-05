/**
 *    author:  MaGnsi0
 *    created: 05.09.2023 01:29:06
**/
#include <bits/stdc++.h>

using namespace std;

struct Line {
    mutable int64_t k, m, p, j;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(int64_t x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
    static const int64_t OO = LLONG_MAX;
    int64_t div(int64_t a, int64_t b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { return x -> p = OO, 0; }
        if (x -> k == y -> k) {
            x -> p = x -> m > y -> m ? OO : -OO;
        } else {
            x -> p = div(y -> m - x -> m, x -> k - y -> k);
        }
        return x -> p >= y -> p;
    }
    void add(int64_t k, int64_t m, int j) {
        auto z = insert({k, m, 0, j}), y = z++, x = y;
        while (isect(y, z)) { z = erase(z); }
        if (x != begin() && isect(--x, y)) { isect(x, y = erase(y)); }
        while ((y = x) != begin() && (--x) -> p >= y -> p) {
            isect(x, erase(y));
        }
    }
    pair<int64_t, int> query(int64_t x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return {l.k * x + l.m, l.j};
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<pair<int, int64_t>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
        adj[v - 1].emplace_back(u - 1, w);
    }
    for (int v = 0; v < n; ++v) {
        sort(adj[v].begin(), adj[v].end());
    }
    vector<int> m(n);
    for (int v = 0; v < n; ++v) {
        m[v] = (int)adj[v].size();
    }
    function<pair<int64_t, int>(int)> farthest = [&](int source) {
        vector<int64_t> D(n, -1);
        queue<int> Q;
        D[source] = 0, Q.push(source);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (auto [u, w] : adj[v]) {
                if (D[u] != -1) { continue; }
                D[u] = D[v] + w, Q.push(u);
            }
        }
        pair<int64_t, int> ans = {0, source}; 
        for (int i = 0; i < n; ++i) {
            ans = max(ans, {D[i], i});
        }
        return ans;
    };
    int64_t diameter = farthest(farthest(0).second).first;
    vector<int64_t> a(n);
    vector<vector<int64_t>> b(n);
    for (int v = 0; v < n; ++v) {
        b[v].resize(m[v]);
    }
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int i = 0; i < m[v]; ++i) {
            int u = adj[v][i].first;
            int64_t w = adj[v][i].second;
            if (u == p) { continue; }
            dfs(u, v);
            b[v][i] = a[u] + w;
            a[v] = max(a[v], a[u] + w);
        }
    };
    dfs(0, -1);
    vector<vector<int64_t>> M(n), C(n);
    for (int v = 0; v < n; ++v) {
        M[v].resize(m[v]);
        C[v].resize(m[v]);
    }
    function<void(int, int)> root = [&](int v, int p) {
        for (int i = 0; i < m[v]; ++i) {
            M[v][i] = adj[v][i].second;
            C[v][i] = a[adj[v][i].first];
        }
        vector<int64_t> pre(m[v]), suf(m[v]);
        pre[0] = b[v][0];
        for (int i = 1; i < m[v]; ++i) {
            pre[i] = max(pre[i - 1], b[v][i]);
        }
        suf[m[v] - 1] = b[v][m[v] - 1];
        for (int i = m[v] - 2; i >= 0; --i) {
            suf[i] = max(suf[i + 1], b[v][i]);
        }
        for (int i = 0; i < m[v]; ++i) {
            int u = adj[v][i].first;
            int64_t w = adj[v][i].second;
            if (u == p) { continue; }
            int j = lower_bound(adj[v].begin(), adj[v].end(), make_pair(u, 0LL)) - adj[v].begin();
            int k = lower_bound(adj[u].begin(), adj[u].end(), make_pair(v, 0LL)) - adj[u].begin();
            int64_t au = a[u], av = a[v];
            int64_t bvu = b[v][j], buv = b[u][k];
            a[u] = max({au, (i ? pre[i - 1] + w : 0), (i + 1 < m[v] ? suf[i + 1] + w : 0)});
            a[v] = max((i ? pre[i - 1] : 0), (i + 1 < m[v] ? suf[i + 1] : 0));
            b[v][j] = 0;
            b[u][k] = a[v] + w;
            root(u, v);
            a[u] = au, av = a[v];
            b[v][j] = bvu, b[u][k] = buv;
        }
    };
    root(0, -1);
    vector<LineContainer> CHT(n);
    for (int v = 0; v < n; ++v) {
        for (int j = 0; j < m[v]; ++j) {
            CHT[v].add(M[v][j], C[v][j], j);
        }
    }
    int Q; cin >> Q;
    vector<map<int, vector<tuple<int, int64_t, int64_t>>>> queries(n);
    for (int q = 0; q < Q; ++q) {
        int v; cin >> v; v--;
        int x; cin >> x;
        pair<int64_t, int> p = CHT[v].query(x);
        queries[v][p.second].emplace_back(q, x, p.first);
    }
    vector<int64_t> ans(Q, diameter);
    for (int v = 0; v < n; ++v) {
        CHT[v] = LineContainer();
        for (int j = 0; j < m[v]; ++j) {
            for (auto [i, x, val1] : queries[v][j]) {
                int64_t val2 = (j ? CHT[v].query(x).first : 0);
                ans[i] = max(ans[i], val1 + val2);
            }
            CHT[v].add(M[v][j], C[v][j], j);
        }
        CHT[v] = LineContainer();
        for (int j = m[v] - 1; j >= 0; --j) {
            for (auto [i, x, val1] : queries[v][j]) {
                int64_t val2 = (j != m[v] - 1 ? CHT[v].query(x).first : 0);
                ans[i] = max(ans[i], val1 + val2);
            }
            CHT[v].add(M[v][j], C[v][j], j);
        }
    }
    for (int q = 0; q < Q; ++q) {
        cout << ans[q] << "\n";
    }
}
