/**
 *    author:  MaGnsi0
 *    created: 10.05.2024 01:31:24
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segment_tree<int> b(n, n, [&](int i, int j) {
        if (i == n) { return j; }
        if (j == n) { return i; }
        return (a[i] < a[j] ? i : j);
    });
    for (int i = 0; i < n; ++i) {
        b.update(i, i);
    }
    function<int(int, int, int)> solve = [&](int low, int high, int take) {
        if (low > high) { return 0; }
        int mid = b.query(low, high + 1);
        return min(high - low + 1, solve(low, mid - 1, a[mid]) + solve(mid + 1, high, a[mid]) + a[mid] - take);
    };
    int ans = solve(0, n - 1, 0);
    cout << ans;
}
