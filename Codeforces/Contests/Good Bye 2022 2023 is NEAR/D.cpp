/**
 *    author:  MaGnsi0
 *    created: 30.12.2022 17:18:28
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<int> I(n);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int i, int j) {
                return ((a[i] == b[i]) > (a[j] == b[j]));
            });
        vector<vector<int>> adj(n + 1);
        vector<bool> visited(n + 1, false);
        for (int i = 0; i < n; ++i) {
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
        }
        function<pair<int, int>(int)> dfs = [&](int v) {
            visited[v] = true;
            pair<int, int> cnt = {(int)adj[v].size(), 1};
            for (auto& u : adj[v]) {
                if (!visited[u]) {
                    pair<int, int> add = dfs(u);
                    cnt.first += add.first;
                    cnt.second += add.second;
                }
            }
            return cnt;
        };
        int64_t ans = 1;
        for (int i = 0; i < n; ++i) {
            int j = I[i];
            if (visited[a[j]]) {
                continue;
            }
            if (a[j] == b[j]) {
                pair<int, int> res = dfs(a[j]);
                if (res.first != 2 * res.second) {
                    ans = 0;
                } else {
                    ans *= n;
                    ans %= MOD;
                }
            } else {
                pair<int, int> res = dfs(a[j]);
                if (res.first != 2 * res.second) {
                    ans = 0;
                } else {
                    ans *= 2;
                    ans %= MOD;
                }
            }
        }
        cout << ans << "\n";
    }
}
