/**
 *    author:  MaGnsi0
 *    created: 20/06/2021 22:42:14
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, k;
    while (cin >> n >> k) {
        vector<int> t(n);
        for (auto& x : t) {
            cin >> x;
        }
        cin.ignore();
        vector<vector<pair<int, int>>> adj(100);
        for (int i = 0; i < n; ++i) {
            int x;
            string s;
            getline(cin, s);
            stringstream cmid(s);
            vector<int> f;
            while (cmid >> x) {
                f.push_back(x);
            }
            for (int u = 0; u < f.size(); ++u) {
                for (int v = u + 1; v < f.size(); ++v) {
                    adj[f[u]].push_back({f[v], i});
                    adj[f[v]].push_back({f[u], i});
                }
            }
        }
        vector<int> d(100, INT_MAX), e(100, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        d[0] = 0;
        q.push({0, 0});
        while (!q.empty()) {
            int v = q.top().second, d_v = q.top().first;
            q.pop();
            if (d[v] != d_v) {
                continue;
            }
            for (auto& [u, i] : adj[v]) {
                int temp = d[v] + abs(v - u) * t[i] + (e[v] != -1 && e[v] != i ? 60 : 0);
                if (temp < d[u]) {
                    d[u] = temp;
                    q.push({temp, u});
                    e[u] = i;
                }
            }
        }
        if (d[k] == INT_MAX) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << d[k] << "\n";
        }
    }
}
