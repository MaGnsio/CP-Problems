//https://www.e-olymp.com/en/contests/8063/problems/67697
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<long long>& S, int v) {
    visited[v] = true;
    int childs = 0;
    for (auto& u : adj[v]) {
        childs++;
        if (visited[u]) {
            S[v] += S[u];
        } else {
            dfs(adj, visited, S, u);
            S[v] += S[u];
        }
    }
    if (childs == 0) {
        S[v] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    while (cin >> N) {
        vector<vector<int>> adj(N + 1);
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                char x;
                cin >> x;
                if (x == 'Y') {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(N + 1, false);
        vector<long long> S(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            if (!visited[i]) {
                dfs(adj, visited, S, i);
            }
        }
        long long total = 0;
        for (auto& x : S) {
            total += x;
        }
        cout << total << "\n";
    }
}
