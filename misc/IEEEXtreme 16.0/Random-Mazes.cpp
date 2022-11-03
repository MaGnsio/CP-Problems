/**
 *    author:  MaGnsi0
 *    created: 22.10.2022 23:13:26
**/
#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, length;
    vector<bool> is_cycle;
    union_find(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(n, 1);
        is_cycle = vector<bool>(n, false);
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
            is_cycle[Px] = true;
            return;
        }
        if (length[Px] < length[Py]) {
            swap(Px, Py);
        }
        parent[Py] = Px;
        length[Px] += length[Py];
        is_cycle[Px] = is_cycle[Px] || is_cycle[Py];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, W;
    cin >> N >> W;
    union_find dsu(N * N);
    while (W--) {
        int x, y;
        char D;
        cin >> x >> y >> D;
        if (D == 'N') {
            if (dsu.find(N * x + y) == dsu.find(0) && dsu.find(N * (x - 1) + y) == dsu.find(N - 1)) {
                cout << "M";
            } else if (dsu.find(N * (x - 1) + y) == dsu.find(0) && dsu.find(N * x + y) == dsu.find(N - 1)) {
                cout << "M";
            } else if (dsu.find(N * x + y) == dsu.find(N * (x - 1) + y) && dsu.find(N * x + y) == dsu.find(0)) {
                cout << "L";
            } else if (dsu.is_cycle[dsu.find(N * x + y)] && dsu.find(N * (x - 1) + y) == dsu.find(0)) {
                cout << "L";
            } else if (dsu.is_cycle[dsu.find(N * (x - 1) + y)] && dsu.find(N * x + y) == dsu.find(0)) {
                cout << "L";
            } else {
                dsu.unite(N * x + y, N * (x - 1) + y);
                if(dsu.find(0) == dsu.find(N * N - 1)) {
                    cout << "T";
                } else {
                    cout << "K";
                }
            }
        }
        if (D == 'E') {
            if (dsu.find(N * x + y) == dsu.find(0) && dsu.find(N * x + (y + 1)) == dsu.find(N - 1)) {
                cout << "M";
            } else if (dsu.find(N * x + (y + 1)) == dsu.find(0) && dsu.find(N * x + y) == dsu.find(N - 1)) {
                cout << "M";
            } else if (dsu.find(N * x + y) == dsu.find(N * x + (y + 1)) && dsu.find(N * x + y) == dsu.find(0)) {
                cout << "L";
            } else if (dsu.is_cycle[dsu.find(N * x + y)] && dsu.find(N * x + (y + 1)) == dsu.find(0)) {
                cout << "L";
            } else if (dsu.is_cycle[dsu.find(N * x + (y + 1))] && dsu.find(N * x + y) == dsu.find(0)) {
                cout << "L";
            } else {
                dsu.unite(N * x + y, N * x + (y + 1));
                if (dsu.find(0) == dsu.find(N * N - 1)) {
                    cout << "T";
                } else {
                    cout << "K";
                }
            }
        }
        if (D == 'W') {
            if (dsu.find(N * x + y) == dsu.find(0) && dsu.find(N * x + (y - 1)) == dsu.find(N - 1)) {
                cout << "M";
            } else if (dsu.find(N * x + (y - 1)) == dsu.find(0) && dsu.find(N * x + y) == dsu.find(N - 1)) {
                cout << "M";
            } else if (dsu.find(N * x + y) == dsu.find(N * x + (y - 1)) && dsu.find(N * x + y) == dsu.find(0)) {
                cout << "L";
            } else if (dsu.is_cycle[dsu.find(N * x + y)] && dsu.find(N * x + (y - 1)) == dsu.find(0)) {
                cout << "L";
            } else if (dsu.is_cycle[dsu.find(N * x + (y - 1))] && dsu.find(N * x + y) == dsu.find(0)) {
                cout << "L";
            } else {
                dsu.unite(N * x + y, N * x + (y - 1));
                if (dsu.find(0) == dsu.find(N * N - 1)) {
                    cout << "T";
                } else {
                    cout << "K";
                }
            }
        }
        if (D == 'S') {
            if (dsu.find(N * x + y) == dsu.find(0) && dsu.find(N * (x + 1) + y) == dsu.find(N - 1)) {
                cout << "M";
            } else if (dsu.find(N * (x + 1) + y) == dsu.find(0) && dsu.find(N * x + y) == dsu.find(N - 1)) {
                cout << "M";
            } else if (dsu.find(N * x + y) == dsu.find(N * (x + 1) + y) && dsu.find(N * x + y) == dsu.find(0)) {
                cout << "L";
            } else if (dsu.is_cycle[dsu.find(N * x + y)] && dsu.find(N * (x + 1) + y) == dsu.find(0)) {
                cout << "L";
            } else if (dsu.is_cycle[dsu.find(N * (x + 1) + y)] && dsu.find(N * x + y) == dsu.find(0)) {
                cout << "L";
            }
            else {
                dsu.unite(N * x + y, N * (x + 1) + y);
                if (dsu.find(0) == dsu.find(N * N - 1)) {
                    cout << "T";
                } else {
                    cout << "K";
                }
            }
        }
        cout << "\n";
    }
}
