/**
 *    author:  MaGnsi0
 *    created: 11.05.2023 09:24:31
**/
#include <bits/stdc++.h>

using namespace std;

const unsigned long long MOD = 1e9 + 7;

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

unsigned long long k1, k2;

unsigned long long xorShift128Plus() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

int n, m, u[100001], v[100001];
unsigned long long w[100001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k1 >> k2;
        for (int i = 0; i < m; ++i) {
            u[i] = xorShift128Plus() % n + 1;
            v[i] = xorShift128Plus() % n + 1;
            w[i] = xorShift128Plus();
        }
        vector<int> I(m);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int i, int j) {
                return w[i] < w[j];
            });
        unsigned long long ans = 0;
        union_find dsu(n);
        for (int i = 0; i < m; ++i) {
            int j = I[i];
            if (dsu.find(u[j] - 1) != dsu.find(v[j] - 1)) {
                dsu.unite(u[j] - 1, v[j] - 1);
                ans += w[j];
                ans %= MOD;
            }
        }
        set<int> p;
        for (int i = 0; i < n; ++i) {
            p.insert(dsu.find(i));
        }
        cout << ((int)p.size() == 1 ? ans : 0) << "\n";
    }
}
