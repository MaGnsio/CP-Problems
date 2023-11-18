/**
 *    author:  MaGnsi0
 *    created: 24.10.2023 07:51:11
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] += x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(n);
    vector<vector<int>> adj(n);
    for (int v = 0; v < n; ++v) {
        cin >> a[v];
        int u; cin >> u; u--;
        if (v == 0) { continue; }
        adj[u].push_back(v);
    }
    int L = 32 - __builtin_clz(n);
    vector<vector<int>> up(n, vector<int>(L + 1));
    function<void(int, int)> dfs = [&](int v, int p) {
        up[v][0] = p;
        for (int i = 1; i <= L; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (int u : adj[v]) {
            dfs(u, v);
        }
    };
    function<int(int, int)> get = [&](int maxA, int v) {
        for (int j = L; j >= 0; --j) {
            if (a[up[v][j]] <= maxA) {
                v = up[v][j];
            }
        }
        return v;
    };
    dfs(0, 0);
    vector<vector<int>> query(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u; u--;
        int minA; cin >> minA;
        int maxA; cin >> maxA;
        query[get(maxA, u)].push_back(minA);
    }
    vector<int> ans(n);
    segment_tree<int> ages(N, 0, [](int x, int y) { return x + y; });
    function<void(int)> solve = [&](int v) {
        for (int x : query[v]) {
            ages.update(x, 1);
        }
        ans[v] = ages.query(0, a[v] + 1);
        for (int u : adj[v]) {
            solve(u);
        }
        for (int x : query[v]) {
            ages.update(x, -1);
        }
    };
    solve(0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
