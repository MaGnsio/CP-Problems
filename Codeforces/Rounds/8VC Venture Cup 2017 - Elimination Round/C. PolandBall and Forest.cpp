/**
 *    author:  MaGnsi0
 *    created: 29/06/2021 19:00:19
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int cc;
    vector<int> parent;
    vector<int> length;
    DSU(int N) {
        cc = N - 1;
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
        cc--;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    DSU D(n + 1);
    for (int x = 1; x <= n; ++x) {
        int y;
        cin >> y;
        D.unite(x, y);
    }
    cout << D.cc;
}
