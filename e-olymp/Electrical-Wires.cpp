//https://www.e-olymp.com/en/contests/8063/problems/67704
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, unordered_set<int>& S, int& x, int& nodes, set<pair<int, int>>& edges, int v) {
    visited[v] = true;
    nodes++;
    if (S.count(v)) {
        x = 1;
    }
    for (auto& u : adj[v]) {
        edges.insert({min(u, v), max(u, v)});
        if (!visited[u]) {
            dfs(adj, visited, S, x, nodes, edges, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    while (cin >> N) {
        vector<vector<int>> adj(N);
        for (int u = 0; u < N; ++u) {
            for (int v = 0; v < N; ++v) {
                char x;
                cin >> x;
                if (x == '1') {
                    adj[u].push_back(v);
                }
            }
        }
        int K;
        unordered_set<int> S;
        cin >> K;
        for (int i = 0; i < K; ++i) {
            int v;
            cin >> v;
            S.insert(v);
        }
        vector<bool> visited(N, false);
        vector<pair<int, int>> A, B;
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                int x = 0, nodes = 0;
                set<pair<int, int>> edges;
                dfs(adj, visited, S, x, nodes, edges, i);
                if (x) {
                    A.push_back({nodes, edges.size()});
                } else {
                    B.push_back({nodes, edges.size()});
                }
            }
        }
        sort(A.begin(), A.end(), greater<pair<int, int>>());
        int ANS = 0;
        for (int i = 0; i < A.size(); ++i) {
            ANS += A[i].first * (A[i].first - 1) / 2 - A[i].second;
        }
        for (int i = 0; i < B.size(); ++i) {
            ANS += B[i].first * (B[i].first - 1) / 2 - B[i].second;
            ANS += A[0].first * B[i].first;
        }
        for (int i = 0; i < B.size(); ++i) {
            for (int j = i + 1; j < B.size(); ++j) {
                ANS += B[i].first * B[j].first;
            }
        }
        cout << ANS << "\n";
    }
}
