/**
 *    author:  MaGnsi0
 *    created: 06.04.2022 02:46:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, root;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> adj(n);
    for (int i = 0, p; i < n; ++i) {
        cin >> p >> a[i];
        if (p) {
            adj[p - 1].push_back(i);
        } else {
            root = i;
        }
    }
    vector<int> ans(n);
    vector<set<int>> b(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        int large = -1;
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            dfs(u, v);
            if (large == -1 || (int)b[u].size() > (int)b[large].size()) {
                large = u;
            }
        }
        if (large != -1) {
            b[v].swap(b[large]);
        }
        b[v].insert(a[v]);
        for (auto& u : adj[v]) {
            if (u == p || u == large) {
                continue;
            }
            for (auto& c : b[u]) {
                b[v].insert(c);
            }
        }
        ans[v] = (int)b[v].size();
    };
    dfs(root, -1);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
