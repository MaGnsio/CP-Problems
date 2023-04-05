/**
 *    author:  MaGnsi0
 *    created: 13.02.2023 10:57:49
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e8;

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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = i - a[i];
    }
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i <= n; ++i) {
        adj[b[i] + i].push_back(i);
    }
    segment_tree<int> c(n + 1, 0, [&](int i, int j) { return (a[i] <= a[j] ? i : j); });
    for (int i = 0; i <= n; ++i) {
        c.update(i, i);
    }
    queue<int> q;
    vector<int> d(n + 1, -1), p(n + 1, -1);
    d[0] = 0, q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        while (true) {
            int u = c.query(v, n + 1);
            if (a[u] > v) { break; }
            a[u] = OO, c.update(u, u);
            for (auto& x : adj[u]) {
                if (d[x] != -1) { continue; }
                d[x] = d[v] + 1, q.push(x);
                p[x] = v;
            }
        }
    }
    int ans = d[n];
    if (ans == -1) {
        cout << -1;
        return 0;
    } else {
        cout << ans << "\n";
    }
    int v = n;
    while (p[v] != -1) {
        cout << p[v] << " ";
        v = p[v];
    }
}
