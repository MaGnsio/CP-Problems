/**
 *    author:  MaGnsi0
 *    created: 15.11.2024 15:05:05
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] = x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> ans(n);
        {
            multiset<int> S(a.begin(), a.end());
            for (int i = n - 1; i >= 0; --i) {
                int x = *S.rbegin();
                ans[i] = x;
                S.erase(S.find(a[i]));
            }
        }
        {
            segment_tree<int> b(n, 0, [&](int x, int y) { return max(x, y); });
            segment_tree<int> c(n, -1, [&](int x, int y) { return max(x, y); });
            for (int i = n - 1; i >= 0; --i) {
                if (c.query(a[i] - 1, a[i]) == -1) {
                    c.update(a[i] - 1, i);
                }
                int j = (a[i] != 1 ? c.query(0, a[i] - 1) : -1);
                ans[i] = max(ans[i], (j != -1 ? b.query(0, j + 1) : 0));
                b.update(i, ans[i]);
            }
        }
        {
            segment_tree<int> b(n, 0, [&](int x, int y) { return max(x, y); });
            segment_tree<int> c(n, n, [&](int x, int y) { return min(x, y); });
            for (int i = 0; i < n; ++i) {
                if (c.query(a[i] - 1, a[i]) == n) {
                    c.update(a[i] - 1, i);
                }
                int j = (a[i] != n ? c.query(a[i], n) : n);
                ans[i] = max(ans[i], (j != n ? b.query(j, n) : 0));
                b.update(i, ans[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
