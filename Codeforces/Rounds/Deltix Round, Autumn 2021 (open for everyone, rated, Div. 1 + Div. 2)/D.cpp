/**
 *    author:  MaGnsi0
 *    created: 28.11.2021 16:27:41
**/
#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> length;
    DSU(int N) {
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
        length.resize(N);
        length.assign(N, 1);
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
    int n, d;
    cin >> n >> d;
    vector<int> x(d), y(d);
    for (int i = 0; i < d; ++i) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }
    for (int i = 0; i < d; ++i) {
        int cnt = 0;
        DSU a(n);
        for (int j = 0; j <= i; ++j) {
            if (a.find(x[j]) == a.find(y[j])) {
                cnt++;
            } else {
                a.unite(x[j], y[j]);
            }
        }
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            if (a.find(i) == i) {
                b.push_back(a.length[i]);
            }
        }
        sort(b.begin(), b.end(), greater<int>());
        int res = 0;
        for (int j = 0; j < min((int)b.size(), cnt + 1); ++j) {
            res += b[j];
        }
        cout << res - 1 << "\n";
    }
}
