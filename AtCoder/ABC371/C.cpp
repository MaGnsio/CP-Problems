/**
 *    author:  MaGnsi0
 *    created: 14.09.2024 15:06:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m1; cin >> m1;
    set<pair<int, int>> E1;
    for (int i = 0; i < m1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        E1.emplace(u, v);
    }
    int m2; cin >> m2;
    vector<int> U2(m2), V2(m2);
    for (int i = 0; i < m2; ++i) {
        cin >> U2[i]; U2[i]--;
        cin >> V2[i]; V2[i]--;
    }
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    int ans = INT_MAX;
    do {
        int res = 0;
        set<pair<int, int>> Eneed = E1;
        for (int i = 0; i < m2; ++i) {
            int u = min(p[U2[i]], p[V2[i]]);
            int v = max(p[U2[i]], p[V2[i]]);
            if (Eneed.count(make_pair(u, v))) {
                Eneed.erase(make_pair(u, v));
                continue;
            }
            res += a[U2[i]][V2[i]];
        }
        vector<int> prev(n);
        for (int i = 0; i < n; ++i) {
            prev[p[i]] = i;
        }
        for (auto [u_, v_] : Eneed) {
            int u = min(prev[u_], prev[v_]);
            int v = max(prev[u_], prev[v_]);
            res += a[u][v];
        }
        ans = min(ans, res);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans;
}
