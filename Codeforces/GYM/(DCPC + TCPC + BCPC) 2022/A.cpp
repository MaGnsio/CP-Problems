/**
 *    author:  MaGnsi0
 *    created: 01.08.2022 21:12:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), g(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> g[i];
        }
        map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < n; ++i) {
            adj[g[i]].push_back(make_pair(a[i], i));
        }
        bool ok = true;
        for (auto& [x, y] : adj) {
            sort(y.begin(), y.end());
            reverse(y.begin(), y.end());
            for (int i = 1; i < (int)y.size(); ++i) {
                if (y[i].first == y[i - 1].first) {
                    ok = false;
                }
            }
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }
        int cur = 1;
        vector<int> ans(n, -1);
        function<void(int)> solve = [&](int x) {
            if (ans[x] != -1) {
                return;
            }
            while (adj[g[x]].back().second != x) {
                ans[adj[g[x]].back().second] = cur++;
                adj[g[x]].pop_back();
            }
            ans[adj[g[x]].back().second] = cur++;
            adj[g[x]].pop_back();
        };
        for (int i = 0; i < n; ++i) {
            solve(i);
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
