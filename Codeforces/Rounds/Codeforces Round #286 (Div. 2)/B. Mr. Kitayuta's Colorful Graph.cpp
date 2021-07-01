/**
 *    author:  MaGnsi0
 *    created: 06/06/2021 19:35:56
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& head, vector<int>& next, vector<int>& to, vector<bool>& visited, vector<int>& color, unordered_set<int>& ans, int v, int target, int c = -1) {
    if (v == target) {
        ans.insert(c);
        return;
    }
    for (int i = head[v]; i != -1; i = next[i]) {
        if (!visited[i] && (color[i] == c || c == -1)) {
            visited[i] = visited[i ^ 1] = true;
            dfs(head, next, to, visited, color, ans, to[i], target, color[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, e = 0;
    cin >> n >> m;
    vector<int> head(n, -1), next(2 * m, -1), to(2 * m, -1), color(2 * m, -1);
    auto addEdge = [&](int u, int v, int c) {
        color[e] = c;
        to[e] = v;
        next[e] = head[u];
        head[u] = e++;
    };
    auto addBiEdge = [&](int u, int v, int c) {
        addEdge(u, v, c);
        addEdge(v, u, c);
    };
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        addBiEdge(u, v, c);
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        unordered_set<int> ans;
        vector<bool> visited(2 * m, false);
        dfs(head, next, to, visited, color, ans, u, v);
        cout << ans.size() << "\n";
    }
}
