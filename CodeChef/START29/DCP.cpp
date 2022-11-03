/**
 *    author:  MaGnsi0
 *    created: 09.03.2022 16:42:46
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> C(m), X(m), eq(n, -1);
    vector<vector<int>> c(m), x(m), adj(n);
    for (int i = 0; i < m; ++i) {
        cin >> C[i] >> X[i];
        c[i].resize(X[i]);
        x[i].resize(X[i]);
        eq[C[i] - 1] = i;
        for (int j = 0; j < X[i]; ++j) {
            cin >> x[i][j] >> c[i][j];
            adj[C[i] - 1].push_back(c[i][j] - 1);
        }
    }
    vector<int> top_sort;
    vector<bool> visited(n, false);
    function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                dfs(u);
            }
        }
        top_sort.push_back(v);
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    assert((int)top_sort.size() == n);
    for (int i = 0; i < n; ++i) {
        int j = eq[top_sort[i]];
        if (j == -1) {
            continue;
        }
        for (int k = 0; k < X[j]; ++k) {
            a[c[j][k] - 1] += 1LL * x[j][k] * a[top_sort[i]];
            a[c[j][k] - 1] %= MOD;
        }
        a[top_sort[i]] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << "\n";
    }
}
