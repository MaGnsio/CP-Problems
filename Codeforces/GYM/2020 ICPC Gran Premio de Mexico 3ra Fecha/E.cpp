/**
 *    author:  MaGnsi0
 *    created: 12.05.2022 22:01:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> deg(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] < a[(i + 1) % n]) {
            adj[i].push_back((i + 1) % n);
            deg[(i + 1) % n]++;
        }
        if (a[i] < a[(i - 1 + n) % n]) {
            adj[i].push_back((i - 1 + n) % n);
            deg[(i - 1 + n) % n]++;
        }
    }
    vector<int> ans(n, 0);
    function<void(int)> bfs = [&](int root) {
        queue<int> q;
        q.push(root);
        ans[root] = (a[root] ? 1 : 0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& u : adj[v]) {
                q.push(u);
                ans[u] = max(ans[u], ans[v] + 1);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            bfs(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << " ";
        }
        cout << 1LL * ans[i] * b;
    }
}
