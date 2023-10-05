/**
 *    author:  MaGnsi0
 *    created: 11.09.2023 18:10:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            adj[i].push_back(a[i]);
        }
        int start = -1;
        vector<int> color(n, -1), visited(n, 0), good(n, 0);
        function<void(int)> dfs = [&](int v) {
            color[v] = 1;
            for (int u : adj[v]) {
                if (color[u] == 1) {
                    start = v;
                }
                if (color[u] == -1) {
                    dfs(u);
                }
            }
            color[v] = 2;
            return false;
        };
        function<int(int)> C = [&](int v) {
            visited[v] = 1;
            int ans = 1;
            for (int u : adj[v]) {
                if (visited[u]) { continue; }
                ans += C(u);
            }
            return ans;
        };
        function<void(int)> mark = [&](int v) {
            good[v] = 1;
            for (int u : adj[v]) {
                if (good[u]) { continue; }
                mark(u);
            }
        };
        for (int i = 0; i < n; ++i) {
            start = -1;
            if (color[i] == -1) {
                dfs(i);
                if (start != -1) {
                    if (C(start) == k) {
                        mark(start);
                    }
                }
            }
        }
        if (k == 1) {
            int cnt = count(good.begin(), good.end(), 1);
            cout << (cnt == n ? "YES" : "NO") << "\n";
            continue;
        }
        function<void(int)> run = [&](int v) {
            good[v] = 0;
            for (int u : adj[v]) {
                if (good[u] == -1) {
                    run(u);
                }
                if (good[u] == 1) {
                    good[v] = 1;
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            good[i] = (good[i] == 0 ? -1 : good[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (good[i] == -1) {
                run(i);
            }
        }
        int cnt = count(good.begin(), good.end(), 1);
        cout << (cnt == n ? "YES" : "NO") << "\n";
    }
}
