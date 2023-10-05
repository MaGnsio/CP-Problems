/**
 *    author:  MaGnsi0
 *    created: 06/07/2021 20:14:47
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    string s, t;
    vector<int> in_deg(26, 0);
    vector<vector<int>> adj(26);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (!i) {
            t = s;
            continue;
        }
        bool ok = false;
        for (int j = 0; j < min(s.size(), t.size()); ++j) {
            if (s[j] != t[j]) {
                adj[t[j] - 'a'].push_back(s[j] - 'a');
                in_deg[s[j] - 'a']++;
                ok = true;
                break;
            }
        }
        if (!ok && s.size() < t.size()) {
            cout << "Impossible";
            return 0;
        }
        t = s;
    }
    vector<int> top_sort;
    queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (!in_deg[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        top_sort.push_back(v);
        for (auto& u : adj[v]) {
            in_deg[u]--;
            if (!in_deg[u]) {
                q.push(u);
            }
        }
    }
    if (top_sort.size() != 26) {
        cout << "Impossible";
    } else {
        for (auto& v : top_sort) {
            cout << char(v + 'a');
        }
    }
}
