/**
 *    author:  MaGnsi0
 *    created: 28.10.2023 20:10:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<string, int> mp1;
    map<int, string> mp2;
    int m = 0;
    vector<int> deg(2 * n);
    vector<vector<int>> adj(2 * n);
    vector<vector<int>> adjT(2 * n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        string x; cin >> x;
        string t; cin >> t;
        if (mp1.count(s) == 0) {
            mp2[m] = s;
            mp1[s] = m++;
        }
        if (mp1.count(t) == 0) {
            mp2[m] = t;
            mp1[t] = m++;
        }
        if (x == "??") {
            adj[mp1[s]].push_back(mp1[t]);
            adj[mp1[t]].push_back(mp1[s]);
            adjT[mp1[s]].push_back(mp1[t]);
            adjT[mp1[t]].push_back(mp1[s]);
        } else {
            adj[mp1[s]].push_back(mp1[t]);
            adjT[mp1[t]].push_back(mp1[s]);
        }
    }
    vector<int> topological_order;
    vector<bool> visited(2 * n, false);
    function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (visited[u]) { continue; }
            dfs(u);
        }
        topological_order.push_back(v);
    };
    function<void()> topological_sort = [&]() {
        for (int i = 0; i < m; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        reverse(topological_order.begin(), topological_order.end());
    };
    function<void(int)> dfs_ = [&](int v) {
        visited[v] = true;
        for (int u : adjT[v]) {
            if (!visited[u]) {
                dfs_(u);
            }
        }
    };
    vector<string> ans;
    function<void()> find_scc = [&]() {
        topological_sort();
        fill(visited.begin(), visited.end(), false);
        dfs_(topological_order[0]);
        for (int i = 0; i < m; ++i) {
            if (!visited[i]) { continue; }
            ans.push_back(mp2[i]);
        }
    };
    find_scc();
    sort(ans.begin(), ans.end());
    for (string name : ans) {
        cout << name << " ";
    }
}
