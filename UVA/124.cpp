/**
 *    author:  MaGnsi0
 *    created: 06/07/2021 18:42:20
**/
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& adj, vector<bool>& picked, vector<int>& in_deg) {
    static vector<int> top_sort;
    static vector<bool> visited(26, false);
    for (int v = 0; v < 26; ++v) {
        if (!picked[v]) {
            continue;
        }
        if (!in_deg[v] && !visited[v]) {
            visited[v] = true;
            top_sort.push_back(v);
            for (auto& u : adj[v]) {
                in_deg[u]--;
            }
            solve(adj, picked, in_deg);
            visited[v] = false;
            top_sort.pop_back();
            for (auto& u : adj[v]) {
                in_deg[u]++;
            }
        }
    }
    if (top_sort.size() == count(picked.begin(), picked.end(), 1)) {
        for (auto& v : top_sort) {
            cout << char(v + 'a');
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    while (cin.peek() != EOF) {
        char x, y = '#';
        string s, t;
        vector<vector<int>> adj(26);
        vector<bool> picked(26, false);
        getline(cin, s);
        stringstream is(s);
        while (is >> x) {
            picked[x - 'a'] = true;
        }
        getline(cin, t);
        stringstream it(t);
        while (it >> x) {
            if (y == '#') {
                y = x;
            } else {
                adj[y - 'a'].push_back(x - 'a');
                y = '#';
            }
        }
        vector<int> in_deg(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < adj[i].size(); ++j) {
                in_deg[adj[i][j]]++;
            }
        }
        solve(adj, picked, in_deg);
        if (cin.peek() != EOF) {
            cout << "\n";
        }
    }
}
