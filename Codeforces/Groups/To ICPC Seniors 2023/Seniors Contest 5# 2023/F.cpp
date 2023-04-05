/**
 *    author:  MaGnsi0
 *    created: 08.02.2023 12:04:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        if (i - a[i] >= 0) {
            adj[i - a[i]].push_back(i);
        }
        if (i + a[i] < n) {
            adj[i + a[i]].push_back(i);
        }
    }
    vector<int> ans(n, -1);
    function<void(int)> solve = [&](int parity) {
        vector<bool> visited(n, false);
        set<pair<int, int>> s;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == parity) {
                visited[i] = true;
                s.emplace(0, i);
            }
        }
        while (!s.empty()) {
            int v = s.begin() -> second;
            int d = s.begin() -> first;
            s.erase(s.begin());
            for (auto& u : adj[v]) {
                if (!visited[u]) {
                    ans[u] = d + 1;
                    visited[u] = true;
                    s.insert({d + 1, u});
                }
            }
        }
    };
    solve(0), solve(1);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
