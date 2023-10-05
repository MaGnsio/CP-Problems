/**
 *    author:  MaGnsi0
 *    created: 08.04.2023 21:28:44
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 10;

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> phi(N), depth(N, 1);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i < N; ++i) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
        depth[i] = depth[phi[i]] - 1;
    }
    set<int> not_ones;
    for (int i = 0; i <= n; ++i) {
        not_ones.insert(i);
    }
    function<int(int, int)> F = [&](int x, int y) {
        if (x == 0) { return y; }
        if (y == 0) { return x; }
        if (x == y) { return y; }
        if (x < y) { swap(x, y); }
        return F(phi[x], y);
    };
    segment_tree<int> b(n, 0, F);
    segment_tree<int> c(n, 0, [](int x, int y) { return x + y; });
    for (int i = 0; i < n; ++i) {
        b.update(i, a[i]);
        c.update(i, depth[a[i]]);
    }
    for (int i = 0; i < m; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1) {
            l = *not_ones.lower_bound(l);
            while (l <= r) {
                a[l] = phi[a[l]];
                b.update(l, a[l]);
                c.update(l, depth[a[l]]);
                if (a[l] == 1) { not_ones.erase(l); }
                l = *not_ones.lower_bound(l + 1);
            }
        } else {
            int x = b.query(l, r + 1);
            int ans = (r - l + 1) * depth[x] - c.query(l, r + 1);
            cout << ans << "\n";
        }
    }
}
