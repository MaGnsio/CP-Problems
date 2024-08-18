/**
 *    author:  MaGnsi0
 *    created: 18.08.2024 20:59:48
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 11;

struct union_find {
    vector<int> parent, length;
    union_find(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(n, 1);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
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
        parent[Py] = Px;
        length[Px] += length[Py];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    int sum = 0;
    vector<union_find> dsu(N, union_find(n));
    for (int i = 0; i < n - 1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        int w; cin >> w; sum += w;
        for (int j = w; j < N; ++j) {
            dsu[j].unite(u, v);
        }
    }
    while (Q--) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        int w, w_ = 0; cin >> w;
        for (int j = 0; j < N; ++j) {
            if (dsu[j].find(u) == dsu[j].find(v)) {
                w_ = j;
                break;
            }
        }
        if (w_ > w) {
            sum += w - w_;
            for (int j = w; j < N; ++j) {
                dsu[j].unite(u, v);
            }
        }
        cout << sum << "\n";
    }
}
