/**
 *    author:  MaGnsi0
 *    created: 08.08.2023 19:10:13
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 11;

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
    int n;
    cin >> n;
    vector<set<pair<int64_t, int>>> a(M);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[y].emplace(x, i);
    }
    vector<tuple<int64_t, int, int>> e;
    for (int y = 0; y < M; ++y) {
        for (auto [x, j] : a[y]) {
            for (int y_ = 0; y_ < M; ++y_) {
                if (y == y_) {
                    auto it = a[y].upper_bound({x, j});
                    if (it != a[y].end()) {
                        int x_ = it -> first;
                        int i = it -> second;
                        e.emplace_back(1LL * (x - x_) * (x - x_), i, j);
                    }
                } else {
                    auto it = a[y_].lower_bound({x, -1});
                    if (it != a[y_].end()) {
                        int x_ = it -> first;
                        int i = it -> second;
                        e.emplace_back(1LL * (x - x_) * (x - x_) + 1LL * (y - y_) * (y - y_), i, j);
                    }
                }
            }
        }
    }
    sort(e.begin(), e.end());
    int64_t ans = 0;
    union_find dsu(n);
    for (auto [w, i, j] : e) {
        if (dsu.find(i) == dsu.find(j)) {
            continue;
        }
        dsu.unite(i, j);
        ans += w;
    }
    cout << ans;
}
