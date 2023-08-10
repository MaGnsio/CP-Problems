/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 22:37:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int, int>> E(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        E[i] = make_tuple(w, u - 1, v - 1, i);
    }
    sort(E.begin(), E.end());
    vector<int> color(n, -1);
    vector<vector<int>> adj(n);
    function<bool(int)> dfs = [&](int v) {
        color[v] = 1;
        for (int u : adj[v]) {
            if (color[u] == 1) {
                return false;
            }
            if (color[u] == -1 && !dfs(u)) {
                return false;
            }
        }
        color[v] = 2;
        return true;
    };
    function<bool(int)> F = [&](int x) {
        color = vector<int>(n, -1);
        adj = vector<vector<int>>(n);
        for (int i = 0; i < m; ++i) {
            if (get<0>(E[i]) > x) {
                adj[get<1>(E[i])].push_back(get<2>(E[i]));
            }
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                ok = ok && dfs(i);
            }
        }
        return ok;
    };
    int low = 0, high = get<0>(E[m - 1]), ans = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (F(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    int dfs_time = 0;
    vector<bool> visited(n, false);
    adj = vector<vector<int>>(n);
    vector<int> top_sort;
    for (int i = 0; i < m; ++i) {
        if (get<0>(E[i]) > ans) {
            adj[get<1>(E[i])].push_back(get<2>(E[i]));
        }
    }
    function<void(int)> dfs_ = [&](int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (visited[u]) { continue; }
            dfs_(u);
        }
        top_sort.push_back(v);
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs_(i);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    vector<int> priority(n);
    for (int i = 0; i < n; ++i) {
        priority[top_sort[i]] = i;
    }
    vector<int> changed;
    for (int i = 0; i < m; ++i) {
        if (get<0>(E[i]) <= ans && priority[get<1>(E[i])] > priority[get<2>(E[i])]) {
            changed.push_back(get<3>(E[i]));
        }
    }
    sort(changed.begin(), changed.end());
    cout << ans << " " << (int)changed.size() << "\n";
    for (int x : changed) {
        cout << x + 1 << " ";
    }
}
