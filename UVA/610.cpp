//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=551
#include <bits/stdc++.h>
using namespace std;

//strong orientation(turn connected undirected graph to strong connected directed graph)
void orient(vector<vector<pair<int, int>>>& adj, vector<bool>& visited_edges, vector<pair<int, int>>& E, vector<int>& in, vector<int>& low, int v) {
    static int time = 0;
    low[v] = in[v] = time++;
    for (auto& [u, i] : adj[v]) {
        if (visited_edges[i]) {
            continue;
        }
        visited_edges[i] = true;
        if (v == E[i].second) {
            swap(E[i].first, E[i].second);
        }
        if (in[u] == -1) { // if u is not visited yet
            orient(adj, visited_edges, E, in, low, u);
            low[v] = min(low[v], low[u]);
            if (in[v] < low[u]) {
                E.push_back({E[i].second, E[i].first});
            }
        } else {
            low[v] = min(low[v], in[u]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M, T = 0;
    while ((cin >> N >> M) && N && M) {
        cout << ++T << "\n\n";
        vector<vector<pair<int, int>>> adj(N + 1);
        vector<bool> visited_edges(M, false);
        vector<pair<int, int>> E(M);
        vector<int> in(N + 1, -1), low(N + 1, -1);
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
            E[i] = {a, b};
        }
        for (int i = 1; i <= N; ++i) {
            if (in[i] == -1) {
                orient(adj, visited_edges, E, in, low, i);
            }
        }
        for (auto& [u, v] : E) {
            cout << u << " " << v << "\n";
        }
        cout << "#\n";
    }
}
