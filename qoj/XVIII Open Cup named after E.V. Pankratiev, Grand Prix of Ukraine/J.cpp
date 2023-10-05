/**
 *    author:  MaGnsi0
 *    created: 30.09.2023 17:14:21
**/
#include <bits/stdc++.h>

using namespace std;

unsigned int S;

unsigned int getNext() {
    S = S ^ (S << 13);
    S = S ^ (S >> 17);
    S = S ^ (S << 5);
    return S;
}

const int Nax = 1e7 + 7;

unsigned int ans[1000000];
int U[Nax], V[Nax], I[Nax], parent[Nax];
unsigned long long W[Nax];

struct union_find {
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
        parent[Py] = Px;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m >> S;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int64_t u = getNext() % n;
        int64_t v = getNext() % n;
        int64_t w = getNext() / 4;
        w = w * getNext();
        U[i] = u, V[i] = v, W[i] = w, I[i] = i;
    }
    sort(I, I + m, [&](int i, int j) {
            return W[i] < W[j];
        });
    int k = (m + 31) / 32;
    union_find dsu;
    for (int i = 0; i < m; ++i) {
        int j = I[i];
        if (dsu.find(U[j]) == dsu.find(V[j])) {
            continue;
        }
        dsu.unite(U[j], V[j]);
        int x = j / 32;
        int y = j - 32 * x;
        ans[x] |= (1LL << y);
    }
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << " ";
    }
}
