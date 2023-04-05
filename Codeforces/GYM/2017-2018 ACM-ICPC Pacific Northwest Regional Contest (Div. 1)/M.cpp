/**
 *    author:  MaGnsi0
 *    created: 09.11.2022 00:05:45
**/
#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj, adj_t;
vector<bool> used, assignment;
vector<int> order, comp;

void dfs1(int v) {
    used[v] = true;
    for (int u : adj[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : adj_t[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }
    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }
    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void add_disjunction(int a, bool na, int b, bool nb) {
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}

void remove_disjunction(int a, bool na, int b, bool nb) {
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].pop_back();
    adj[neg_b].pop_back();
    adj_t[b].pop_back();
    adj_t[a].pop_back();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    n = 2 * n + 2;
    adj = adj_t = vector<vector<int>>(n);
    int m;
    cin >> m;
    bool two = false;
    while(m--) {
        int u, v;
        cin >> u >> v;
        if (u < 0 && v < 0) {
            two = true;
        }
        add_disjunction(abs(u), u < 0, abs(v), v < 0);
    }
    bool ok = solve_2SAT();
    if (ok == false) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < n / 2; ++i) {
        used = assignment = vector<bool>(n, false);
        order = comp = vector<int>(n, 1);
        add_disjunction(i, 0, i, 0);
        if (!solve_2SAT()) {
            cout << 1;
            return 0;
        }
        remove_disjunction(i, 0, i, 0);
    }
    cout << (two ? 2 : -1);
}
