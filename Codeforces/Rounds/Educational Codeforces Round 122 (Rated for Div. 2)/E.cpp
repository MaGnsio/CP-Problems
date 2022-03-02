/**
 *    author:  MaGnsi0
 *    created: 01.02.2022 04:50:00
**/
#include <bits/stdc++.h>

using namespace std;

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
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> E(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        E[i] = make_tuple(w, u, v);
    }
    sort(E.begin(), E.end());
    vector<int> T;
    T.push_back(-1);
    for (int i = 0; i < m; ++i) {
        T.push_back(get<0>(E[i]));
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            T.push_back((get<0>(E[i]) + get<0>(E[j]) + 1) / 2);
        }
    }
    sort(T.begin(), T.end());
    T.erase(unique(T.begin(), T.end()), T.end());
    int s = (int)T.size();
    vector<long long> A(s, 0), B(s, 0);
    for (int i = 0; i < s; ++i) {
        vector<tuple<int, int, int, int, int>> E2(m);
        for (int j = 0; j < m; ++j) {
            int w = get<0>(E[j]);
            int u = get<1>(E[j]);
            int v = get<2>(E[j]);
            if (w <= T[i]) {
                E2[j] = make_tuple(abs(T[i] - w), 1, -w, u, v);
            } else {
                E2[j] = make_tuple(abs(T[i] - w), -1, w, u, v);
            }
        }
        sort(E2.begin(), E2.end());
        union_find uf(n);
        for (int j = 0; j < m; ++j) {
            int u = get<3>(E2[j]);
            int v = get<4>(E2[j]);
            if (uf.find(u) != uf.find(v)) {
                uf.unite(u, v);
                A[i] += get<1>(E2[j]);
                B[i] += get<2>(E2[j]);
            }
        }
    }
    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    vector<int> Q(k);
    for (int i = 0; i < p; ++i) {
        cin >> Q[i];
    }
    for (int i = p; i < k; ++i) {
        Q[i] = ((long long) Q[i - 1] * a + b) % c;
    }
    long long res = 0;
    for (int i = 0; i < k; ++i) {
        int j = upper_bound(T.begin(), T.end(), Q[i]) - T.begin() - 1;
        res ^= (A[j] * Q[i] + B[j]);
    }
    cout << res;
}
