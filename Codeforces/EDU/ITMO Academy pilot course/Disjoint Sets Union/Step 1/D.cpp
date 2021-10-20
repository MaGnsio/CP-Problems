/**
 *    author:  MaGnsi0
 *    created: 24/06/2021 17:43:36
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> length;
    DSU(int N) {
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(N, 1);
    }
    int find(int x) {
        int root = x;
        if (parent[root] != root) {
            parent[root] = find(parent[root]);
        }
        return parent[root];
    }
    void unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) {
            return;
        }
        if (length[a] < length[b]) {
            swap(a, b);
        }
        parent[b] = a;
        length[a] += length[b];
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, k;
    cin >> n >> m >> k;
    DSU a(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
    }
    vector<pair<int, pair<int, int>>> op;
    for (int i = 0; i < k; ++i) {
        int x, y;
        string s;
        cin >> s >> x >> y;
        if (s == "cut") {
            op.push_back({1, {x, y}});
        } else {
            op.push_back({2, {x, y}});
        }
    }
    reverse(op.begin(), op.end());
    vector<string> ans;
    for (auto& [i, p] : op) {
        int x = p.first, y = p.second;
        if (i == 1) {
            a.unite(x, y);
        } else {
            ans.push_back(a.find(x) == a.find(y) ? "YES" : "NO");
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto& s : ans) {
        cout << s << "\n";
    }
}
