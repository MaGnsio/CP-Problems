/**
 *    author:  MaGnsi0
 *    created: 27.08.2023 16:10:46
**/
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

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
    vector<int> F(N, -1);
    for (int i = 2; i < N; ++i) {
        if (F[i] == -1) {
            for (int j = i; j < N; j += i) {
                F[j] = max(F[j], i);
            }
        }
    }
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int maxP = 1;
    for (int i = 0; i < n; ++i) {
        maxP = max(maxP, F[a[i]]);
    }
    int T = 0;
    for (int i = 0; i < n; ++i) {
        while (a[i] > maxP) {
            a[i] /= F[a[i]];
            T++;
        }
    }
    set<pair<int, int>> S;
    for (int i = 0; i < n; ++i) {
        S.emplace(-a[i], i);
    }
    vector<int> time(n, 0);
    while (!S.empty()) {
        int x = -S.begin() -> first;
        int j = S.begin() -> second;
        S.erase(S.begin());
        int largest = (S.empty() ? 0 : -S.begin() -> first);
        int i = (S.empty() ? -1 : S.begin() -> second);
        while (x != 1 && make_pair(-x, j) < make_pair(-largest, i)) {
            x /= F[x];
            time[j] = ++T;
        }
        if (x != 1) { S.emplace(-x, j); }
    }
    segment_tree<int> s(n, 0, [](int x, int y) { return max(x, y); });
    for (int i = 0; i < n; ++i) {
        s.update(i, time[i]);
    }
    while (Q--) {
        int low, high;
        cin >> low >> high;
        cout << s.query(low - 1, high) << "\n";
    }
}
