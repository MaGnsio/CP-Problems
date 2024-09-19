/**
 *    author:  MaGnsi0
 *    created: 20.09.2024 00:42:53
**/
#include <bits/stdc++.h>

using namespace std;

struct segment {
    int L, R;
    int64_t X;
    segment() {}
    segment(int L, int R, int64_t X) : L(L), R(R), X(X) {}
};

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

void compress(vector<segment>& a) {
    set<int> S;
    for (auto [L, R, _] : a) {
        S.insert(L);
        S.insert(R);
    }
    unordered_map<int, int> I;
    for (auto p : S) {
        I[p] = (int)I.size();
    }
    for (auto& [L, R, _] : a) {
        L = I[L], R = I[R];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<segment> a(n);
        for (int i = 0; i < n; ++i) {
            int L; cin >> L;
            int R; cin >> R;
            int64_t X; cin >> X;
            a[i] = segment(L, R, X);
        }
        compress(a);
        vector<vector<pair<int64_t, int>>> start(2 * n + 1), end(2 * n + 1);
        for (int i = 0; i < n; ++i) {
            auto [L, R, X] = a[i];
            start[L].emplace_back(X, i);
            end[R + 1].emplace_back(X, i);
        }
        bool started = false, bad = false;
        vector<tuple<int64_t, int, int>> E;
        set<pair<int, int>> Xs;
        for (int p = 0; p <= 2 * n; ++p) {
            for (auto xj : end[p]) {
                Xs.erase(xj);
            }
            if (started && Xs.empty() && !start[p].empty()) {
                bad = true;
            }
            for (auto [X, j] : start[p]) {
                if (!Xs.empty()) {
                    auto it = Xs.lower_bound(make_pair(X, -1));
                    if (it != Xs.end()) {
                        E.emplace_back(abs(X - it -> first), j, it -> second);
                    }
                    if (it != Xs.begin()) {
                        it--;
                        E.emplace_back(abs(X - it -> first), j, it -> second);
                    }
                }
                Xs.emplace(X, j);
                started = true;
            }
        }
        if (bad) {
            cout << -1 << "\n";
            continue;
        }
        sort(E.begin(), E.end());
        int64_t ans = 0;
        union_find dsu(n);
        for (auto [W, U, V] : E) {
            if (dsu.find(U) == dsu.find(V)) { continue; }
            dsu.unite(U, V);
            ans += W;
        }
        cout << ans << "\n";
    }
}
