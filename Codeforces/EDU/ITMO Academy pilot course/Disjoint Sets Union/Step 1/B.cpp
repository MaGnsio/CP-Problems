/**
 *    author:  MaGnsi0
 *    created: 24/06/2021 01:59:58
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> length;
    vector<int> max_element;
    vector<int> min_element;
    DSU(int N) {
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
        length.resize(N);
        length.assign(N, 1);
        max_element.resize(N);
        iota(max_element.begin(), max_element.end(), 0);
        min_element.resize(N);
        iota(min_element.begin(), min_element.end(), 0);
    }
    int find(int x) {
        int root = x;
        if (parent[root] != root) {
            parent[root] = find(parent[root]); //path compression optimization
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int Px = find(x);
        int Py = find(y);
        if (Px == Py) {
            return;
        }
        if (length[Px] < length[Py]) {
            swap(Px, Py);
        }
        max_element[Px] = max(max_element[Px], max_element[Py]);
        min_element[Px] = min(min_element[Px], min_element[Py]);
        length[Px] += length[Py];
        parent[Py] = Px;
    }
    void get(int x) {
        int p = find(x);
        cout << min_element[p] << " " << max_element[p] << " " << length[p] << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    DSU a(n + 1);
    while (m--) {
        string c;
        cin >> c;
        if (c == "union") {
            int x, y;
            cin >> x >> y;
            a.unite(x, y);
        } else {
            int x;
            cin >> x;
            a.get(x);
        }
    }
}
