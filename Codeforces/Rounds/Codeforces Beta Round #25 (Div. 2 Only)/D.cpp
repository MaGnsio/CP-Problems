/**
 *    author:  MaGnsi0
 *    created: 28/06/2021 02:44:41
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
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
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
        length[a] += length[b];
        parent[b] = a;
    }
    vector<pair<int, int>> add() {
        set<int> s;
        vector<pair<int, int>> added;
        for (int i = 1; i < parent.size(); ++i) {
            s.insert(find(i));
        }
        int x = *s.begin();
        s.erase(s.begin());
        for (auto& y : s) {
            added.push_back({x, y});
        }
        return added;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    DSU D(n + 1);
    vector<pair<int, int>> added, removed;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        if (D.find(x) == D.find(y)) {
            removed.push_back({x, y});
        } else {
            D.unite(x, y);
        }
    }
    added = D.add();
    cout << added.size() << "\n";
    for (int i = 0; i < added.size(); ++i) {
        cout << removed[i].first << " " << removed[i].second << " " << added[i].first << " " << added[i].second << "\n";
    }
}
