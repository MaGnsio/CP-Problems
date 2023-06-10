/**
 *    author:  MaGnsi0
 *    created: 05.06.2023 03:47:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> in(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        in[v - 1]++;
    }
    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i];
    }
    vector<int> top_sort;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) { q.push(i); }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            in[u]--;
            if (in[u] == 0) { q.push(u); }
        }
        top_sort.push_back(v);
    }
    if ((int)top_sort.size() != n) {
        cout << "No";
        return 0;
    }
    reverse(top_sort.begin(), top_sort.end());
    for (int v : top_sort) {
        for (int u : adj[v]) {
            R[v] = min(R[v], R[u] - 1);
            in[u]++;
        }
    }
    set<pair<int, int>> s, early;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            if (L[i] > 1) {
                early.emplace(L[i], i);
            } else {
                s.emplace(R[i], i);
            }
        }
    }
    int x = 1;
    vector<int> ans(n);
    while (!s.empty()) {
        int v = s.begin() -> second;
        s.erase(s.begin());
        if (R[v] < x) {
            cout << "No";
            return 0;
        }
        ans[v] = x++;
        while ((!early.empty()) && ((early.begin() -> first) <= x)) {
            int j = early.begin() -> second;
            s.emplace(R[j], j);
            early.erase(early.begin());
        }
        for (int u : adj[v]) {
            in[u]--;
            if (in[u] == 0) {
                if (L[u] > x) {
                    early.emplace(L[u], u);
                } else {
                    s.emplace(R[u], u);
                }
            }
        }
    }
    if (x != n + 1) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
