/**
 *    author:  MaGnsi0
 *    created: 19.09.2023 22:56:15
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, th;
    cin >> n >> th;
    vector<int64_t> X(n), Y(n), Z(n), W(n);
    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i];
        cin >> Z[i] >> W[i];
    }
    vector<int64_t> c(N, 0), cw(N, 0);
    vector<vector<int>> adj(N);
    for (int i = 0; i < n; ++i) {
        adj[Y[i]].push_back(X[i]);
        adj[Z[i]].push_back(X[i]);
        c[X[i]] = W[i];
    }
    vector<int> done(N, 0);
    function<void(int, int)> dfs = [&](int s, int v) {
        cw[s] += c[v];
        done[v] = 1;
        for (int u : adj[v]) {
            if (done[u]) { continue; }
            dfs(s, u);
        }
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < N; ++j) {
            done[j] = 0;
        }
        dfs(i, i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (cw[X[i]] >= th) {
            cout << X[i] << " " << cw[X[i]] << "\n";
            ans++;
        }
    }
    cout << ans;
}
