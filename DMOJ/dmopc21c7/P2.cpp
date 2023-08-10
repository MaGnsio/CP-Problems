/**
 *    author:  MaGnsi0
 *    created: 17.04.2023 23:10:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 2, -1), c(n + 2, -1);
    for (int i = 1; i <= n + 1; ++i) {
        p[i] = i - 1;
    }
    for (int i = 0; i <= n; ++i) {
        c[i] = i + 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        if (p[u] == k) { continue; }
        int pu = p[u], pv = p[v], pk = p[k];
        int cu = c[u], cv = c[v], ck = c[k];
        p[u] = k, c[k] = u;
        p[ck] = v, c[v] = ck;
        p[cv] = pu, c[pu] = cv;
    }
    int v = c[0];
    vector<int> ans;
    while (ans.size() < n) {
        ans.push_back(v);
        v = c[v];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
