/**
 *    author:  MaGnsi0
 *    created: 13.09.2023 18:13:57
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] = x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        if (L == R) { return E; }
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
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; ++v) {
        int u; cin >> u; u--;
        adj[u].push_back(v);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> S(a.begin(), a.end());
    map<int, int> mp;
    for (int x : S) {
        mp[x] = (int)mp.size();
    }
    int m = (int)mp.size();
    vector<vector<int>> ans(n, vector<int>(2));
    segment_tree<int> b(m, 0, [](int x, int y) { return max(x, y); });
    function<void(int)> dfs = [&](int v) {
        int j = mp[a[v]];
        int x = b.query(j, j + 1);
        ans[v][0] = b.query(0, m);
        ans[v][1] = b.query(0, j) + 1;
        b.update(j, max(ans[v][1], x));
        for (int u : adj[v]) { dfs(u); }
        b.update(j, x);
    };
    dfs(0);
    for (int i = 1; i < n; ++i) {
        cout << max(ans[i][0], ans[i][1]) << " ";
    }
}
