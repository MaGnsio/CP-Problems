/**
 *    author:  MaGnsi0
 *    created: 09/07/2021 23:15:24
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& in, vector<int>& low, vector<bool>& in_stack, stack<int>& st, int& t, int& sccs, int v) {
    in[v] = low[v] = t++;
    st.push(v);
    in_stack[v] = true;
    for (auto& u : adj[v]) {
        if (!in[u]) {
            dfs(adj, in, low, in_stack, st, t, sccs, u);
        }
        if (in_stack[u]) {
            low[v] = min(low[u], low[v]);
        }
    }
    if (low[v] == in[v]) {
        while (st.top() != v) {
            int u = st.top();
            st.pop();
            in_stack[u] = false;
            low[u] = in[v];
        }
        st.pop();
        in_stack[v] = false;
        sccs++;
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, t = 1, sccs = 0;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    stack<int> st;
    vector<int> in(n + 1, 0), low(n + 1, 0);
    vector<bool> in_stack(n + 1, false);
    for (int v = 1; v <= n; ++v) {
        if (!in[v]) {
            dfs(adj, in, low, in_stack, st, t, sccs, v);
        }
    }
    cout << sccs;
}
