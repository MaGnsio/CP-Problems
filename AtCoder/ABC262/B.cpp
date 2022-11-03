/**
 *    author:  MaGnsi0
 *    created: 13.08.2022 15:51:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        s.emplace(u, v);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                ans += (s.count({i, j}) && s.count({j, k}) && s.count({i, k}));
            }
        }
    }
    cout << ans;
}
