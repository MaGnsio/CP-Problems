/**
 *    author:  MaGnsi0
 *    created: 27/06/2021 19:15:05
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
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
        parent[b] = a;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    DSU D(n + 1);
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        int root = D.find(x);
        cout << root << " ";
        D.unite((root == n ? 1 : root + 1), root);
    }
}
