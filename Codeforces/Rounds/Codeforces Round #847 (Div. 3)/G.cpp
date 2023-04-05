/**
 *    author:  MaGnsi0
 *    created: 27.01.2023 18:29:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<bool> have_token(n, false), have_bonus(n, false);
        int p, b;
        cin >> p >> b;
        for (int i = 0; i < p; ++i) {
            int v;
            cin >> v;
            have_token[v - 1] = true;
        }
        for (int i = 0; i < b; ++i) {
            int v;
            cin >> v;
            have_bonus[v - 1] = true;
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        if (have_token[0]) {
            cout << "YES\n";
            continue;
        }
        int one_move = 0;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (!have_token[i]) {
                continue;
            }
            bool good = false;
            for (auto& j : adj[i]) {
                good = good | have_bonus[j];
            }
            one_move += good;
        }
        for (auto& u : adj[0]) {
            ok = ok | have_token[u];
            if (!have_bonus[u]) {
                continue;
            }
            for (auto& k : adj[u]) {
                ok = ok | (have_token[k] && one_move > 1);
            }
        }
        if (ok) {
            cout << "YES\n";
            continue;
        }
        int infinity_moves = 0;
        vector<bool> good(n, false);
        for (int i = 0; i < n; ++i) {
            if (!have_bonus[i]) {
                continue;
            }
            for (auto& j : adj[i]) {
                good[i] = good[i] | have_bonus[j];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (have_token[i]) {
                ok = good[i];
                for (auto& j : adj[i]) {
                    ok = ok | good[j];
                }
                infinity_moves += ok;
            }
        }
        if (infinity_moves < 2) {
            vector<int> d(n, -1);
            queue<int> q;
            q.push(0);
            d[0] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto& u : adj[v]) {
                    if (d[u] != -1) {
                        continue;
                    }
                    if (have_token[u]) {
                        d[u] = d[v] + 1;
                    }
                    if (have_bonus[u]) {
                        q.push(u);
                        d[u] = d[v] + 1;
                    }
                }
            }
            int j = -1, mind = 1e9, cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (have_token[i] && d[i] != -1 && d[i] < mind) {
                    mind = d[i];
                    j = i;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (j == i || !have_token[i]) {
                    continue;
                }
                for (auto& u : adj[i]) {
                    if (have_bonus[u]) {
                        cnt++;
                        break;
                    }
                }
            }
            cout << (mind - 1 <= cnt ? "YES" : "NO") << "\n";
        } else {
            vector<bool> visited(n, false);
            function<bool(int)> dfs = [&](int v) {
                visited[v] = true;
                bool ans = have_token[v];
                for (auto& u : adj[v]) {
                    if (have_token[u]) {
                        ans = true;
                        break;
                    }
                    if (have_bonus[u] && !visited[u]) {
                        ans = ans | dfs(u);
                    }
                }
                return ans;
            };
            cout << (dfs(0) ? "YES" : "NO") << "\n";
        }
    }
}
