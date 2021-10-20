/**
 *    author:  MaGnsi0
 *    created: 06/07/2021 16:42:49
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& top_sort, int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs(adj, visited, top_sort, u);
        }
    }
    top_sort.push_back(v);
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s, prev = "";
    vector<vector<int>> adj(26);
    vector<bool> visited(26, false), taken(26, false);
    while ((cin >> s) && (s != "#")) {
        if (prev == "") {
            prev = s;
            continue;
        }
        for (int i = 0; i < min(s.size(), prev.size()); ++i) {
            if (s[i] != prev[i]) {
                taken[s[i] - 'A'] = taken[prev[i] - 'A'] = true;
                adj[prev[i] - 'A'].push_back(s[i] - 'A');
                break;
            }
        }
        prev = s;
    }
    vector<int> top_sort;
    for (int i = 0; i < 26; ++i) {
        if (!taken[i]) {
            continue;
        }
        if (!visited[i]) {
            dfs(adj, visited, top_sort, i);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    for (auto& v : top_sort) {
        cout << char(v + 'A');
    }
    cout << "\n";
}
