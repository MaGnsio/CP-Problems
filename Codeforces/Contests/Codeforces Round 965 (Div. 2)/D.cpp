/**
 *    author:  MaGnsi0
 *    created: 10.08.2024 18:31:40
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> best(n, -1);
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            best[u] = max(best[u], v);
            adj[u].push_back(v);
        }
        for (int i = 0; i + 1 < n; ++i) {
            adj[i].push_back(i + 1);
        }
        vector<int> fast(n, -1);
        queue<int> Q;
        fast[0] = 0; Q.push(0);
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int u : adj[v]) {
                if (fast[u] == -1) {
                    fast[u] = fast[v] + 1;
                    Q.push(u);
                }
            }
        }
        string ans = "";
        segment_tree<int> b(n, -1, [](int x, int y) { return max(x, y); });
        for (int i = 0; i + 1 < n; ++i) {
            b.update(i, -1);
            ans += (i < b.query(0, n) ? '0' : '1');
            if (best[i] == -1) { continue; }
            int j = best[i];
            int val = max(b.query(j, j + 1), j - fast[i] - 1);
            b.update(best[i], val);
        }
        cout << ans << "\n";
    }
}
