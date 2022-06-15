/**
 *    author:  MaGnsi0
 *    created: 11.03.2022 22:38:35
**/
#include <bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 5, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("safe.in", "r", stdin);
    vector<long long> P2(N, 1);
    for (int i = 1; i < N; ++i) {
        P2[i] = 2LL * P2[i - 1];
        P2[i] %= MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n), adjT(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adjT[v - 1].push_back(u - 1);
        }
        vector<int> tp;
        vector<bool> visited(n, false);
        function<void(int)> topological_order = [&](int v) {
            visited[v] = true;
            for(auto& u : adj[v]) {
                if (!visited[u]) {
                    topological_order(u);
                }
            }
            tp.push_back(v);
        };
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                topological_order(i);
            }
        }
        assert((int)tp.size() == n);
        reverse(tp.begin(), tp.end());
        vector<int> cur_scc;
        vector<vector<int>> scc;
        function<void(int)> dfs = [&](int v) {
            visited[v] = true;
            cur_scc.push_back(v);
            for (auto& u : adjT[v]) {
                if (!visited[u]) {
                    dfs(u);
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }
        for (auto& v : tp) {
            if (!visited[v]) {
                dfs(v);
                scc.push_back(cur_scc);
                cur_scc.clear();
            }
        }
        long long ans = 0, cnt = 1;
        for (int i = 0; i < (int)scc.size(); ++i) {
            vector<long long> points;
            for (auto& v : scc[i]) {
                points.push_back(a[v]);
            }
            sort(points.begin(), points.end());
            long long scc_points = 0;
            for (int j = 0; j < (int)points.size(); ++j) {
                if (points[j] > 0LL) {
                    scc_points += points[j];
                }
            }
            if (scc_points == 0) {
                if (count(points.begin(), points.end(), 0) > 0) {
                    long long bcnt = 0;
                    for (int j = 0; j < (int)points.size(); ++j) {
                        bcnt += (points[j] == 0);
                    }
                    cnt = (cnt * ((P2[bcnt] - 1 + MOD) % MOD)) % MOD;
                    cnt %= MOD;
                } else {
                    long long bcnt = 0;
                    for (int j = 0; j < (int)points.size(); ++j) {
                        bcnt += (points[j] == points[(int)points.size() - 1]);
                    }
                    cnt = (cnt * (bcnt % MOD)) % MOD;
                    cnt %= MOD;
                    ans += points[(int)points.size() - 1];
                }
            } else {
                long long bcnt = 0;
                for (int j = 0; j < (int)points.size(); ++j) {
                    bcnt += (points[j] == 0LL);
                }
                cnt = (cnt * P2[bcnt] % MOD) % MOD;
                cnt %= MOD;
                ans += scc_points;
            }
        }
        cout << ans << " " << cnt << "\n";
    }
}
