/**
 *    author:  MaGnsi0
 *    created: 25.11.2023 17:23:50
**/
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

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
    int T; cin >> T;
    bitset<N> sums(0); sums[0] = 1;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        segment_tree<int> b(n, 0, [](int x, int y) { return x + y; });
        for (int i = 0; i < n; ++i) {
            b.update(i, a[i]);
            sums[b.query(0, i + 1)] = 1;
        }
        while (Q--) {
            int t; cin >> t;
            if (t == 1) {
                int s; cin >> s;
                cout << ((sums & (sums << s)) == 0 ? "NO" : "YES") << "\n";
            } else {
                int j; cin >> j; j--;
                int x; cin >> x;
                if (x == a[j]) { continue; }
                int s = b.query(0, j + 1);
                a[j] = x, b.update(j, x);
                if (x == 1) {
                    sums = ((sums << (N - s)) >> (N - s)) | (((sums >> s) << s) >> 1);
                } else {
                    sums = ((sums << (N - s)) >> (N - s)) | (((sums >> s) << s) << 1);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            sums[b.query(0, i + 1)] = 0;
        }
    }
}
